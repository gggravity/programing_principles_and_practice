//
// Created by martin on 10/19/22.
//
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/frame.h>

#include <utility>
#include <ostream>
#include "../std_lib.h"

struct Line
    {
        Line (string name, string address, string phone, string purchase, double unit_price, int count) :
            name(std::move(name)),
            address(std::move(address)),
            phone(std::move(phone)),
            purchase(std::move(purchase)),
            unit_price(unit_price),
            count(count)
          {
          
          }
        
        string name;
        string address;
        string phone;
        string purchase;
        double unit_price;
        int count;
        
        friend ostream &operator<< (ostream &os, const Line &line)
          {
            os << "name: " << line.name << " address: " << line.address << " phone: " << line.phone << " purchase: "
               << line.purchase << " unit_price: " << line.unit_price << " count: " << line.count;
            return os;
          }
      
    };

auto load_data (const string &filename)
  {
    vector<Line> lines;
    ifstream ifs { filename };
    
    if (!ifs.is_open())
      {
        cerr << "ERROR: Can't open file: " << filename << endl;
        exit(EXIT_FAILURE);
      }
    for (string line ; getline(ifs, line) ;)
      {
        auto s { split(line, ';') };
        lines.emplace_back(s[0], s[1], s[2], s[3], stod(s[4]), stoi(s[5]));
      }
    return lines;
  }

class Model_columns : public Gtk::TreeModel::ColumnRecord
  {
  public:
    
    Model_columns ()
      {
        add(col_name);
        add(col_address);
        add(col_phone);
        add(col_purchase);
        add(col_unit_price);
        add(col_amount);
      }
    
    Gtk::TreeModelColumn<string> col_name;
    Gtk::TreeModelColumn<string> col_address;
    Gtk::TreeModelColumn<string> col_phone;
    Gtk::TreeModelColumn<string> col_purchase;
    Gtk::TreeModelColumn<double> col_unit_price;
    Gtk::TreeModelColumn<int> col_amount;
  };

struct Window : public Gtk::Window
    {
        Window () :
            choose_button(make_unique<Gtk::Button>("Choose file")),
            load_button(make_unique<Gtk::Button>("Load file")),
            save_button(make_unique<Gtk::Button>("Save data to file")),
            filename("/home/martin/src/programing_principles_and_practice/c21/new_order.txt")
          {
            set_title("Basic application");
            set_default_size(1000, 800);
            filename_entry.set_text(filename);
            
            name_entry.set_placeholder_text("Enter name of purchaser");
            address_entry.set_placeholder_text("Enter address of purchaser");
            phone_entry.set_placeholder_text("Enter phone of purchaser");
            purchase_entry.set_placeholder_text("Enter name of item");
            price_entry.set_placeholder_text("Enter price of item");
            amount_entry.set_placeholder_text("Enter amount brought");
            
            auto vbox = Gtk::Box(Gtk::Orientation::VERTICAL, 10);
            auto fbox = Gtk::Box(Gtk::Orientation::VERTICAL, 10);
            
            frame.set_child(fbox);
            fbox.append(filename_entry);
            fbox.append(*choose_button);
            fbox.append(*load_button);
            
            auto enter_box = Gtk::Box(Gtk::Orientation::VERTICAL, 10);
            form_frame.set_child(enter_box);
            enter_box.append(name_entry);
            enter_box.append(address_entry);
            enter_box.append(phone_entry);
            enter_box.append(purchase_entry);
            enter_box.append(price_entry);
            enter_box.append(amount_entry);
            enter_box.append(*save_button);
            
            //Add the TreeView, inside a ScrolledWindow, with the button underneath:
            scrolled_window.set_child(treeview);
            
            //Only show the scrollbars when they are necessary:
            scrolled_window.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
            scrolled_window.set_expand();
            
            vbox.append(scrolled_window);
            
            //Create the Tree model:
            refTreeModel = Gtk::ListStore::create(columns);
            treeview.set_model(refTreeModel);
            
            //Add the TreeView's view columns:
            //This number will be shown with the default numeric formatting.
            treeview.append_column("Name", columns.col_name);
            treeview.append_column("Address", columns.col_address);
            treeview.append_column("Phone", columns.col_phone);
            treeview.append_column("Purchase", columns.col_purchase);
            treeview.append_column("Price", columns.col_unit_price);
            treeview.append_column("Amount", columns.col_amount);
            
            for (auto column : treeview.get_columns())
              {
                column->set_reorderable();
                column->set_min_width(120);
              }
            
            vbox.append(form_frame);
            form_frame.set_label("Insert data");
            form_frame.set_margin(10);
            
            vbox.append(frame);
            frame.set_label("Load data");
            frame.set_margin(10);
            
            set_child(vbox);
            
            load_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_load_button_clicked));
            choose_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_button_file_clicked));
            save_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_save_button_clicked));
          }
        
        void on_button_file_clicked ()
          {
            auto dialog = new Gtk::FileChooserDialog("Please choose a file", Gtk::FileChooser::Action::OPEN);
            dialog->set_transient_for(*this);
            dialog->set_modal(true);
            dialog->signal_response()
                .connect(sigc::bind(sigc::mem_fun(*this, &Window::on_file_dialog_response), dialog));
            
            //Add response buttons to the dialog:
            dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
            dialog->add_button("_Open", Gtk::ResponseType::OK);
            
            //Add filters, so that only certain file types can be selected:
            
            auto filter_text = Gtk::FileFilter::create();
            filter_text->set_name("Text files");
            filter_text->add_mime_type("text/plain");
            dialog->add_filter(filter_text);
            
            auto filter_any = Gtk::FileFilter::create();
            filter_any->set_name("Any files");
            filter_any->add_pattern("*");
            dialog->add_filter(filter_any);
            
            //Show the dialog and wait for a user response:
            dialog->show();
          }
        
        void on_file_dialog_response (int response_id, Gtk::FileChooserDialog *dialog)
          {
            //Handle the response:
            switch (response_id)
              {
                case Gtk::ResponseType::OK:
                  {
                    std::cout << "Open clicked." << std::endl;
                    
                    //Notice that this is a std::string, not a Glib::ustring.
                    filename = dialog->get_file()->get_path();
                    filename_entry.set_text(filename);
                    std::cout << "File selected: " << filename << std::endl;
                    break;
                  }
                case Gtk::ResponseType::CANCEL:
                  {
                    std::cout << "Cancel clicked." << std::endl;
                    break;
                  }
                default:
                  {
                    std::cout << "Unexpected button clicked." << std::endl;
                    break;
                  }
              }
            delete dialog;
          }
        
        void on_load_button_clicked ()
          {
            cout << "Load button clicked!" << endl;
            auto results { load_data(filename) };
            
            refTreeModel->clear();
            
            for (const auto &line : results)
              {
                auto row = *( refTreeModel->append() );
                row[columns.col_name] = line.name;
                row[columns.col_phone] = line.phone;
                row[columns.col_address] = line.address;
                row[columns.col_purchase] = line.purchase;
                row[columns.col_unit_price] = line.unit_price;
                row[columns.col_amount] = line.count;
              }
          }
        
        void on_save_button_clicked ()
          {
            cout << "Save button clicked!" << endl;
            
            ofstream ofs { filename, ios_base::app };
            
            if (!ofs.is_open())
              {
                cerr << "Can't save data to: " << filename << endl;
                exit(EXIT_FAILURE);
              }
            
            auto row = *( refTreeModel->append() );
            row[columns.col_name] = name_entry.get_text();
            row[columns.col_phone] = phone_entry.get_text();
            row[columns.col_address] = address_entry.get_text();
            row[columns.col_purchase] = purchase_entry.get_text();
            row[columns.col_unit_price] = stod(price_entry.get_text());
            row[columns.col_amount] = stoi(amount_entry.get_text());
            
            ofs << endl << name_entry.get_text() << ";"
                << address_entry.get_text() << ";"
                << phone_entry.get_text() << ";"
                << purchase_entry.get_text() << ";"
                << stod(price_entry.get_text()) << ";"
                << stoi(amount_entry.get_text()) << flush;

//            for (auto row : refTreeModel->children())
//              {
//                //Do something with the row - see above for set/get.
//                ofs << string(row[columns.col_name]) << ";"
//                     << string(row[columns.col_address]) << ";"
//                     << string(row[columns.col_phone]) << ";"
//                     << string(row[columns.col_purchase]) << ";"
//                     << double(row[columns.col_unit_price]) << ";"
//                     << int(row[columns.col_amount]) << endl;
//              }
            ofs.close();
          }
        
        ~Window () override
          {
            cout << "window closed" << endl;
          }
        
        unique_ptr<Gtk::Button> load_button;
        unique_ptr<Gtk::Button> choose_button;
        unique_ptr<Gtk::Button> save_button;
        Gtk::Entry filename_entry;
        
        Gtk::Entry name_entry;
        Gtk::Entry address_entry;
        Gtk::Entry phone_entry;
        Gtk::Entry purchase_entry;
        Gtk::Entry price_entry;
        Gtk::Entry amount_entry;
        
        string filename;
        Model_columns columns;
        
        Gtk::ScrolledWindow scrolled_window;
        Gtk::TreeView treeview;
        Glib::RefPtr<Gtk::ListStore> refTreeModel;
        
        Gtk::Frame frame;
        Gtk::Frame form_frame;
    };

int main (int argc, char *argv[])
  {
    auto app = Gtk::Application::create("org.gtkmm.example");
    
    //Shows the window and returns when it is closed.
    return app->make_window_and_run<Window>(argc, argv);
    
    return EXIT_SUCCESS;
  }
