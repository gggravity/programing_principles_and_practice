//
// Created by martin on 16-10-22.
//

//#define DEBUG

#include "../std_lib.h"


int main (int argc, char *argv[])
try
  {

    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

