//
// Created by martin on 16-10-22.
//

#define DEBUG

#include "../std_lib.h"

vector<double> convert_to_vector_of_double (const list<int> &list_of_ints)
  {
    vector<double> vd(list_of_ints.size());
    
    copy(list_of_ints, vd);
    
    return vd;
  }

bool verify (const list<int> &list_of_ints, const vector<double> &vector_of_double)
  {
    if (list_of_ints.size() != vector_of_double.size())
      {
        return false;
      }
    
    auto iter1 { list_of_ints.begin() };
    auto iter2 { vector_of_double.begin() };
    
    while (iter2 < vector_of_double.end())
      {
        auto d = static_cast<double>(*iter1);
        if (d != *iter2)
          {
#ifdef DEBUG
            cout << red("d: ") << d << " " << red("iter2: ") << *iter2 << endl;
#endif
            return false;
          }
        iter1++;
        iter2++;
      }
    return true;
  }

int main (int argc, char *argv[])
try
  {
    list<int> li { 6, 1, 9, 3, 7, 5, 6, 4, 7, 9 };
    
    auto vd { convert_to_vector_of_double(li) };
    
    print(vd);
    
    cout << boolalpha << verify(li, vd) << endl;
    
    sort(vd);
    
    print(vd);
    
    cout << boolalpha << verify(li, vd) << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

