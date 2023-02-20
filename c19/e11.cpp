//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>
#include "Counted_ptr.hpp"

using namespace std;

int main (int argc, char *argv[])
try
  {
    auto ptr1 = Counted_ptr<int>(new int(1234567890));
    
    cout << "ptr1: " << *ptr1 << endl;
    
    auto ptr2 = ptr1;
    Counted_ptr<int> ptr3 = ptr2;
    ptr3 = ptr1;
    
    cout << "ptr1 counter: " << ptr1.get_count() << endl;
    
    auto r = ptr1.release();
    
    cout << "*ptr2: " << *ptr2 << endl;
    
    cout << "*r: " << *r << endl;
    
    free(r);
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
