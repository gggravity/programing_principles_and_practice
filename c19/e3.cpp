//
// Created by martin on 09-10-22.
//

#include <bits/stdc++.h>

#include <utility>
#include <ostream>

using namespace std;

template < typename T, typename U >
struct Pair
    {
        Pair (T name, U value)
            :
            name(std::move(name)),
            value(std::move(value))
          {
          
          }
        
        friend ostream &operator<< (ostream &os, const Pair &p)
          {
            os << "name: " << setw(12) << left << p.name << " value: " << setw(12) << p.value;
            return os;
          }
        
        T name;
        U value;
    };

template < typename T >
void print (const vector<T> &v)
  {
    for (auto const &elem : v)
      {
        cout << elem << endl;;
      }
  }

int main (int argc, char *argv[])
try
  {
    Pair pair { 1, "2" };
    
    vector<Pair<string, string>> pair_table;
    
    pair_table.emplace_back("Anna", "56");
    pair_table.emplace_back("Paul", "47");
    pair_table.emplace_back("Peter", "18");
    pair_table.emplace_back("Katrina", "23");
    pair_table.emplace_back("Morten", "34");
    
    print(pair_table);
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
