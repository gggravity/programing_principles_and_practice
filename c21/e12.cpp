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
            filename("/home/martin/src/programing_principles_and_practice/c21/new_order.txt")
          {
            set_title("Search DB application");
            set_default_size(1000, 800);
            
            auto vbox = Gtk::Box(Gtk::Orientation::VERTICAL, 10);
            
            //Add the TreeView, inside a ScrolledWindow, with the button underneath:
            scrolled_window.set_child(treeview);
            
            //Only show the scrollbars when they are necessary:
            scrolled_window.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
            scrolled_window.set_expand();
            
            vbox.append(entry);
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
            
            set_child(vbox);

//            load_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_load_button_clicked));
//            choose_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_button_file_clicked));
//            save_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_save_button_clicked));
            import_data();
            
            entry.set_placeholder_text("Please enter text to filter...");
            
            //Add an EntryCompletion:
            auto completion = Gtk::EntryCompletion::create();
            entry.set_completion(completion);
            
            //Create and fill the completion's filter model
//            auto refCompletionModel = Gtk::ListStore::create(columns);
            completion->set_model(refTreeModel);
            
            
            // For more complex comparisons, use a filter match callback, like this.
            // See the comment below for more details:
//            completion->set_match_func(sigc::mem_fun(*this, &Window::on_completion_match));
            
            
            //Tell the completion what model column to use to
            //- look for a match (when we use the default matching, instead of
            //  set_match_func().
            //- display text in the entry when a match is found.
            completion->set_text_column(columns.col_name);
            completion->set_text_column(columns.col_address);
            
          }
        
        /*
         * You can do more complex matching with a handler like this.
         * For instance, you could check for substrings inside the string instead of the start,
         * or you could look for the key in extra model columns as well as the model column that will be displayed.
         *  The code here is not actually more complex - it's a reimplementation of the default behaviour.
         */
        
        bool on_completion_match (const string &key, const Gtk::TreeModel::const_iterator &iter)
          {
//            if (iter)
//              {
//                const auto row = *iter;
//
//                const auto key_length = key.size();
//                auto filter_string = string(row[columns.col_name]);
//
//                auto filter_string_start = filter_string.substr(0, key_length);
//                //The key is lower-case, even if the user input is not.
////                filter_string_start = filter_string_start.lowercase();
//
//                if (key == filter_string_start)
//                  {
//                    return true;
//                  } //A match was found.
//              }
//
//            return false; //No match.
            cout << "Match: " << key << endl;
            return true;
          }
        
        void import_data ()
          {
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
        
        ~Window () override
          {
            cout << "window closed" << endl;
          }
        
        Gtk::Entry entry;
        string filename;
        Model_columns columns;
        
        Gtk::ScrolledWindow scrolled_window;
        Gtk::TreeView treeview;
        Glib::RefPtr<Gtk::ListStore> refTreeModel;
    };

int main (int argc, char *argv[])
  {
    auto app = Gtk::Application::create("org.gtkmm.example");
    
    //Shows the window and returns when it is closed.
    return app->make_window_and_run<Window>(argc, argv);
    
    return EXIT_SUCCESS;
  }
