//
// Created by martin on 10/18/22.
//

#include "../std_lib.h"

template < typename T >
auto binary_search (vector<T> v, T to_find)
  {
    int low = 0;
    auto high = int(v.size() - 1);
    // This below check covers all cases , so need to check
    // for mid=low-(high-low)/2
    while (high - low > 1)
      {
        int middle = ( high + low ) / 2;
        if (v[middle] < to_find)
          {
            low = middle + 1;
          }
        else
          {
            high = middle;
          }
      }
    if (v[low] == to_find)
      {
        cout << "Found \"" << to_find << "\" at index " << low << endl;
        return low;
      }
    else if (v[high] == to_find)
      {
        cout << "Found \"" << to_find << "\" at index " << high << endl;
        return high;
      }
    else
      {
        cout << "\"" << to_find << "\" not found" << endl;
        return -1;
      }
  }

int main (int argc, char *argv[])
  {
    header("int test", true);
    
    vector<int> vi = { 9, 1, 3, 5, 4, 5, 6 };
    sort(vi);
    print(vi);
    binary_search(vi, 5);
    
    header("string test");
    vector<string> vs = { "James Bond",
                          "King Kong",
                          "Jeanne d'Arc",
                          "Dr. Who",
                          "Bruce Lee",
                          "Jason Bourne",
                          "Vlad the Impaler" };
    sort(vs);
    print(vs);
    binary_search(vs, string("Dr. Who"));
    
    return EXIT_SUCCESS;
  }
