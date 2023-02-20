//
// Created by martin on 10/19/22.
//

#include <ostream>
#include <utility>
#include "../std_lib.h"

template < typename T >
void print_db (const T &map)
  {
    for (const auto &[key, value] : map)
      {
        cout << key << ": " << value << endl;
      }
  }

struct Order_line
    {
        Order_line (string customer_name, string address, string phone, string product_name, double unit_price, int count) :
            customer_name(std::move(customer_name)),
            address(std::move(address)),
            phone(std::move(phone)),
            product_name(std::move(product_name)),
            unit_price(unit_price),
            count(count)
          {
          
          }
        
        bool operator< (const Order_line &rhs) const
          {
            if (customer_name < rhs.customer_name)
              {
                return true;
              }
            if (customer_name < rhs.customer_name)
              {
                return true;
              }
            if (address < rhs.address)
              {
                return true;
              }
            if (address < rhs.address)
              {
                return true;
              }
            if (phone < rhs.phone)
              {
                return true;
              }
            if (phone < rhs.phone)
              {
                return true;
              }
            if (product_name < rhs.product_name)
              {
                return true;
              }
            if (product_name < rhs.product_name)
              {
                return true;
              }
            if (unit_price < rhs.unit_price)
              {
                return true;
              }
            if (unit_price < rhs.unit_price)
              {
                return true;
              }
            return count<rhs.count;
          }
        
        bool operator== (const Order_line &rhs) const
          {
            return customer_name == rhs.customer_name &&
                   address == rhs.address &&
                   phone == rhs.phone &&
                   product_name == rhs.product_name &&
                   unit_price == rhs.unit_price &&
                   count == rhs.count;
          }
        
        bool operator!= (const Order_line &rhs) const
          {
            return !( rhs == *this );
          }
        
        string customer_name;
        string address;
        string phone;
        string product_name;
        double unit_price;
        int count;
        
        friend ostream &operator<< (ostream &os, const Order_line &line)
          {
            os << line.customer_name << ";"
               << line.address << ";"
               << line.phone << ";"
               << line.product_name << ";"
               << line.unit_price << ";"
               << line.count;
            return os;
          }
    };

struct Customer
    {
        string address;
        string phone;
        
        friend ostream &operator<< (ostream &os, const Customer &customer)
          {
            os << " address: " << customer.address << " phone: " << customer.phone;
            return os;
          }
    };

struct Purchase
    {
        string name;
        double unit_price;
        int count;
        
        friend ostream &operator<< (ostream &os, const Purchase &purchase)
          {
            os << purchase.name << " $" << purchase.unit_price << " " << purchase.count;
            return os;
          }
    };

struct Order
    {
        vector<Purchase> purchases;
        
        friend ostream &operator<< (ostream &os, const Order &order)
          {
            os << order.purchases;
            return os;
          }
    };

void load_data (map<string, Customer> &customer_map, map<string, Order> &order_map)
  {
    ifstream ifs { "../c21/orders.txt" };
    
    if (!ifs.is_open())
      {
        cerr << "Can't open file." << endl;
        exit(EXIT_FAILURE);
      }
    for (string line ; getline(ifs, line) ;)
      {
        auto s { split(line, ';') };
        string name = s[0];
        customer_map[name] = { s[1], s[2] };
        
        Purchase purchase { s[3], stod(s[4]), stoi(s[5]) };
        
        order_map[name].purchases.push_back(purchase);
      }
  }

auto load_new_data ()
  {
    map<string, Order> order_map;
    ifstream ifs { "../c21/new_order.txt" };
    
    if (!ifs.is_open())
      {
        cerr << "Can't open file." << endl;
        exit(EXIT_FAILURE);
      }
    for (string line ; getline(ifs, line) ;)
      {
        auto s { split(line, ';') };
        string name = s[0];
        
        Purchase purchase { s[3], stod(s[4]), stoi(s[5]) };
        
        order_map[name].purchases.push_back(purchase);
      }
    return order_map;
  }

void save_data (map<string, Customer> &customer_map, map<string, Order> &order_map)
  {
    ofstream ofs { "../c21/orders_output.txt" };
    
    if (!ofs.is_open())
      {
        cerr << "Can't save data." << endl;
        exit(EXIT_FAILURE);
      }
    for (auto [name, data] : customer_map)
      {
        for (auto &p : order_map[name].purchases)
          {
            ofs << name << ";"
                << data.address << ";"
                << data.phone << ";"
                << p.name << ";"
                << p.unit_price << ";"
                << p.count << endl;
          }
      }
    ofs.close();
  }

auto to_vector (map<string, Customer> &customer_map, map<string, Order> &order_map)
  {
    vector<Order_line> lines;
    for (auto [name, data] : customer_map)
      {
        for (auto &p : order_map[name].purchases)
          {
            lines.emplace_back(name, data.address, data.phone, p.name, p.unit_price, p.count);
          }
      }
    return lines;
  }

auto to_list (map<string, Customer> &customer_map, map<string, Order> &order_map)
  {
    list<Order_line> lines;
    for (auto [name, data] : customer_map)
      {
        for (auto &p : order_map[name].purchases)
          {
            lines.emplace_back(name, data.address, data.phone, p.name, p.unit_price, p.count);
          }
      }
    return lines;
  }

int main (int argc, char *argv[])
  {
    map<string, Customer> customer_map;
    map<string, Order> order_map;
    
    load_data(customer_map, order_map);
    
    header("customer db", true);
    print_db(customer_map);
    header("order db");
    print_db(order_map);
    
    save_data(customer_map, order_map);
    
    auto new_orders { load_new_data() };
    
    header("new orders");
    
    print_db(new_orders);
    
    header("merged orders");
    
    auto first_orders = to_vector(customer_map, order_map);
    
    sort(first_orders);
    
    auto next_orders = to_list(customer_map, new_orders);
    
    next_orders.sort();
    
    vector<Order_line> merged;
    
    merge(first_orders.begin(), first_orders.end(),
          next_orders.begin(), next_orders.end(),
          back_inserter<vector<Order_line> >(merged)
    );
    
    for (const auto &line : merged)
      {
        cout << line << endl;
      }
    
    return EXIT_SUCCESS;
  }
