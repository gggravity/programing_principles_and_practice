//
// Created by martin on 10-10-22.
//

#include <bits/stdc++.h>

#include <utility>
#include <ostream>
#include "Link.hpp"

using namespace std;

struct God
    {
        string name;
        string mythology;
        string vehicle;
        string weapon;
        
        God (string name, string mythology, string vehicle, string weapon)
            :
            name(std::move(name)),
            mythology(std::move(mythology)),
            vehicle(std::move(vehicle)),
            weapon(std::move(weapon))
          {
          
          }
        
        friend ostream &operator<< (ostream &os, const God &god)
          {
            os << "name: " << god.name << " mythology: " << god.mythology << " vehicle: " << god.vehicle << " weapon: "
               << god.weapon;
            return os;
          }
    };

template < typename T >
void print_vector (const vector<T> &vector, bool new_lines = true)
  {
    if (new_lines)
      {
        for (auto const &elem : vector)
          {
            cout << elem << endl;
          }
      }
    else
      {
        for (auto const &elem : vector)
          {
            cout << elem << " ";
          }
        cout << endl;
      }
  }

template < typename T >
void print_linked_list (T *linked_list, bool reverse_order = false)
  {
    if (reverse_order)
      {
        // Base case
        if (linked_list == nullptr)
          {
            return;
          }
        // print the list after head node
        print_linked_list(linked_list->next(), true);
        
        // After everything else is printed, print head
        
        if (linked_list->next() == nullptr)
          {
            cout << "{ ";
          }
        if (linked_list->previous() != nullptr)
          {
            cout << linked_list->value << ", ";
          }
        else
          {
            cout << linked_list->value;
          }
      }
    else
      {
        cout << "{ ";
        while (linked_list)
          {
            cout << linked_list->value;
            linked_list = linked_list->next();
            if (linked_list)
              {
                cout << ", ";
              }
          }
        cout << " }" << endl;
      }
    if (reverse_order && linked_list->previous() == nullptr)
      {
        cout << " }" << endl;
      }
  }

template < typename T >
void print_linked_list_of_structs (T *linked_list)
  {
    while (linked_list)
      {
        cout << linked_list->value;
        linked_list = linked_list->next();
        if (linked_list)
          {
            cout << endl;
          }
      }
  }

int main (int argc, char *argv[])
try
  {
    vector<int> vi { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    print_vector(vi, false);
    
    auto norse_gods = new Link { "Thor" };
    norse_gods = norse_gods->insert(new Link { "Odin" });
    norse_gods = norse_gods->insert(new Link { "Zeus" });
    norse_gods = norse_gods->insert(new Link { "Freia" });
    
    auto greek_gods = new Link { "Hera" };
    greek_gods = greek_gods->insert(new Link { "Athena" });
    greek_gods = greek_gods->insert(new Link { "Mars" });
    greek_gods = greek_gods->insert(new Link { "Poseidon" });
    
    auto numbers = new Link { 1 };
    for (auto i { 2 } ; i <= 10 ; ++i)
      {
        numbers = numbers->insert(new Link { i });
      }
    
    print_linked_list(norse_gods);
    
    print_linked_list(greek_gods);
    
    print_linked_list(numbers);
    
    cout << "--------- Reverse order ---------" << endl;
    
    print_linked_list(norse_gods, true);
    
    print_linked_list(greek_gods, true);
    
    print_linked_list(numbers, true);
    
    cout << "--------- Gods ---------" << endl;
    
    auto gods = new Link { God("Zeus", "Greek", "", "lightning") };
    gods = gods->insert(new Link {
        God("Odin", "Norse", "Eight-legged flying horse called Sleiper", "Spear called Gungnir") });
    
    print_linked_list_of_structs(gods);
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
