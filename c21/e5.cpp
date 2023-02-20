//
// Created by martin on 10/18/22.
//

#include "../std_lib.h"

template < typename Iterator, typename T >
auto count (Iterator first, Iterator last, T to_count)
  {
    auto counter = 0;
    for (auto iterator { first } ; iterator != last ; ++iterator)
      {
        if (*iterator == to_count)
          {
            ++counter;
          }
      }
    return counter;
  }

template < typename Iterator, typename T >
auto find (Iterator first, Iterator last, T to_find)
  {
    int counter { 0 };
    for (auto i { first } ; i < last ; ++i, ++counter)
      {
        if (*i == to_find)
          {
            return counter;
          }
      }
    return -1;
  }

int main (int argc, char *argv[])
  {
    header("count ints", true);
    
    vector<int> vi { 1, 3, 4, 3, 4, 3, 4, 2, 6, 7, 4, 5, 7, 1, 1, 2, 3, 0 };
    vector<string> vs { "Anna", "Dr. Who", "John", "Peter", "Anna", "Paul" };
    
    cout << ::count(vi.begin(), vi.end(), 1) << endl;
    cout << std::count(vi.begin(), vi.end(), 1) << endl;
    
    header("count strings");
    
    cout << "Anna: " << ::count(vs.begin(), vs.end(), "Anna") << endl;
    cout << "Anna: " << std::count(vs.begin(), vs.end(), "Anna") << endl;
    cout << "Peter: " << ::count(vs.begin(), vs.end(), "Peter") << endl;
    cout << "Peter: " << std::count(vs.begin(), vs.end(), "Peter") << endl;
    
    header("find 4");
    
    cout << "index: " << ::find(vi.begin(), vi.end(), 4) << endl;
    cout << "value: " << *std::find(vi.begin(), vi.end(), 4) << endl;
    
    header("find string");
    
    cout << "Dr. Who at index : " << ::find(vs.begin(), vs.end(), "Dr. Who") << endl;
    cout << "value: " << *std::find(vs.begin(), vs.end(), "Dr. Who") << endl;
    cout << "Peter at index: " << ::find(vs.begin(), vs.end(), "Peter") << endl;
    cout << "value: " << *std::find(vs.begin(), vs.end(), "Peter") << endl;
    
    return EXIT_SUCCESS;
  }
