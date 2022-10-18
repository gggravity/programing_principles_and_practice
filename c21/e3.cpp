//
// Created by martin on 10/18/22.
//

#include "../std_lib.h"

template < typename Iterator, typename T >
auto count (Iterator first, Iterator last, const T &value)
  {
    auto counter = 0;
    for (auto iterator { first } ; iterator != last ; ++iterator)
      {
        if (*iterator == value)
          {
            ++counter;
          }
      }
    return counter;
  }

int main (int argc, char *argv[])
  {
    header("ints", true);
    
    vector<int> vi { 1, 3, 4, 3, 4, 3, 4, 2, 6, 7, 4, 5, 7, 1, 1, 2, 3, 0 };
    
    cout << ::count(vi.begin(), vi.end(), 1) << endl;
    cout << std::count(vi.begin(), vi.end(), 1) << endl;
    
    header("strings");
    
    vector<string> vs { "Anna", "John", "Peter", "Anna", "Paul" };
    
    cout << "Anna: " << ::count(vs.begin(), vs.end(), "Anna") << endl;
    cout << "Anna: " << std::count(vs.begin(), vs.end(), "Anna") << endl;
    cout << "Peter: " << ::count(vs.begin(), vs.end(), "Peter") << endl;
    cout << "Peter: " << std::count(vs.begin(), vs.end(), "Peter") << endl;
    
    return EXIT_SUCCESS;
  }
