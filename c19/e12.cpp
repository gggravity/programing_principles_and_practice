//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>
#include "File_handle.hpp"

using namespace std;

int main (int argc, char *argv[])
try
  {
    auto file_handle = File_handle("../c19/e12.cpp");
    
    auto fh = file_handle.get();
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
