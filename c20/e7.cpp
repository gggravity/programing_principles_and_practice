//
// Created by martin on 16-10-22.
//

#include "../std_lib.h"

template < typename Container >
string find_last_lexicographical (Container container)
  {
    string last;
    for (const auto &item : container)
      {
        if (item > last)
          {
            last = item;
          }
      }
    return last;
  }

int main (int argc, char *argv[])
try
  {
    vector<string> vec { "Amanda", "Karen", "Zebra", "Xavia", "Mikkel", "Karl", "Max" };
    
    auto last { find_last_lexicographical(vec) };
    
    print(vec);
    
    cout << last << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

