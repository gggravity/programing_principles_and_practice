//
// Created by martin on 10/18/22.
//

#include "../std_lib.h"

template < typename Iterator, typename Predicate >
auto count_if (Iterator first, Iterator last, Predicate predicate)
  {
    auto counter = 0;
    for (auto iterator { first } ; iterator != last ; ++iterator)
      {
        if (predicate(*iterator))
          {
            ++counter;
          }
      }
    return counter;
  }

bool eq_one (int i)
  {
    return i == 1;
  }

bool eq_anna (const string &s)
  {
    return s == "Anna";
  }

bool eq_peter (const string &s)
  {
    return s == "Peter";
  }
  
int main (int argc, char *argv[])
  {
    header("ints", true);
    
    vector<int> vi { 1, 3, 4, 3, 4, 3, 4, 2, 6, 7, 4, 5, 7, 1, 1, 2, 3, 0 };
    
    cout << ::count_if(vi.begin(), vi.end(), eq_one) << endl;
    cout << std::count_if(vi.begin(), vi.end(), eq_one) << endl;
    
    header("strings");
    
    vector<string> vs { "Anna", "John", "Peter", "Anna", "Paul" };
    
    cout << "Anna: " << ::count_if(vs.begin(), vs.end(), eq_anna) << endl;
    cout << "Anna: " << std::count_if(vs.begin(), vs.end(), eq_anna) << endl;
    cout << "Peter: " << ::count_if(vs.begin(), vs.end(), eq_peter) << endl;
    cout << "Peter: " << std::count_if(vs.begin(), vs.end(), eq_peter) << endl;
    
    return EXIT_SUCCESS;
  }
