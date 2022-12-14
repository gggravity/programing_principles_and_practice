//
// Created by martin on 10/18/22.
//

#include <ostream>
#include <utility>
#include "../std_lib.h"

struct Fruit
    {
        Fruit (string name, int count = 0, double unit_price = 0.0f) :
            name(std::move(name)),
            count(count),
            unit_price(unit_price)
          {
          
          }
        
        virtual ~Fruit ()
          {
            cout << "Killing " << name << endl;
          }
        
        string name;
        int count;
        double unit_price;
        
        friend ostream &operator<< (ostream &os, const Fruit &fruit)
          {
            os << "{ " << fruit.name << ", " << fruit.count << ", " << fruit.unit_price << " }";
            return os;
          }
    };

struct Fruit_order
    {
        bool operator() (const Fruit &lhs, const Fruit &rhs) const
          {
            return lhs.name < rhs.name;
          }
    };

struct Fruit_comparison
    {
        bool operator() (const Fruit *lhs, const Fruit *rhs) const
          {
            return lhs->name < rhs->name;
          }
    };

struct Fruit_comparison_shared_ptr
    {
        bool operator() (const shared_ptr<Fruit>& lhs, const shared_ptr<Fruit>& rhs) const
          {
            return lhs->name < rhs->name;
          }
    };

int main (int argc, char *argv[])
  {
    header("set<Fruit, Fruit_order>", true);
    
    set<Fruit, Fruit_order> inventory;
    
    inventory.insert({ "quince", 5 });
    inventory.insert({ "apple", 200, 0.37 });
    
    print(inventory);
    
    header("set<Fruit*, Fruit_comparison>");

    set<Fruit *, Fruit_comparison> inventory_ptr;

    // Valgrind warning
    inventory_ptr.insert(new Fruit { "quince", 5 });
    inventory_ptr.insert(new Fruit { "apple", 200, 0.37 });

    for (const auto &item : inventory_ptr)
      {
        cout << *item << " ";
      }
    cout << endl;
    
    header("set<shared_ptr<Fruit>, Fruit_comparison_shared_ptr>");
    
    set<shared_ptr<Fruit>, Fruit_comparison_shared_ptr> inventory_shared_ptr;

    // no valgrind warnings
    inventory_shared_ptr.insert(make_shared<Fruit>("quince", 5));
    inventory_shared_ptr.insert(make_shared<Fruit>("apple", 200, 0.37));
    
    for (const auto &item : inventory_shared_ptr)
      {
        cout << *item << " ";
      }
    cout << endl;
    
    return EXIT_SUCCESS;
  }
