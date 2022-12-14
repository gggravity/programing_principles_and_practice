//
// Created by martin on 10/22/22.
//

#include "../std_lib.h"
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

struct Triple
    {
        int operator() (int &i)
          {
            return i *= 3;
          }
    };

int main (int argc, char *argv[])
  {
    Matrix<int> m({ 1, 2, 3, 4, 5 });
    
    cout << m << endl;
    
    auto m2 = m.apply(Triple());
    
    cout << m2 << endl;
    
    auto m3 = Numeric_lib::apply(Triple(), m2);
    
    cout << m3 << endl;
    
    return EXIT_SUCCESS;
  }
