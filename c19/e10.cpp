//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>
#include "Unique_ptr.hpp"


using namespace std;

int main (int argc, char *argv[])
try
  {
    
    auto ptr = Unique_ptr<int>(new int());
    
    cout << *ptr << endl;
    
    auto r = ptr.release();
    
    cout << *r << endl;
    cout << *ptr << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
