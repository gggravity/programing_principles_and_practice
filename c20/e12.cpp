//
// Created by martin on 16-10-22.
//

//#define DEBUG

#include "../std_lib.h"
#include "List.hpp"

int main (int argc, char *argv[])
try
  {
    List<int> list;
    
    List<int>::iterator it = list.begin();
    it = list.insert(it, 10);
    it = list.insert(it, 20);
    it = list.insert(it, 30);
    it = list.insert(it, 40);
//    list.push_front(123);
    
    auto h = high(list.begin(),list.end());
    
    cout << *h << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

