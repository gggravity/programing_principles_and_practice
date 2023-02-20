//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>
#include "Tracer.hpp"

using namespace std;

Tracer global_tracer { "global tracer" };

struct Test
    {
        Tracer t { "Test tracker" };
        Tracer *t_ptr { new Tracer("Test ptr tracker") };
        
        virtual ~Test ()
          {
            delete t_ptr;
          }
    };

void f1 (const Tracer &t)
  {
    cout << "f1 running..." << endl;
  }

void f2 (Tracer t)
  {
    cout << "f2 running..." << endl;
  }

int main (int argc, char *argv[])
try
  {
    Tracer main_tracer { "main tracer" };
    
    Test test;
    
    f1(Tracer("f1 tracer"));
    
    f2(Tracer("f2 tracer"));
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
