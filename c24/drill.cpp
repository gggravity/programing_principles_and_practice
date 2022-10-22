//
// Created by martin on 10/22/22.
//

#include "../std_lib.h"
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

void print_sqrt (int min, int max)
  {
    using namespace terminal_colors;
    while (min != max)
      {
        errno = 0;
        auto square_root { sqrt(min) };
        if (!errno)
          {
            cout << "Square root of " << min << " = " << fixed << square_root << endl;
          }
        else
          {
            cout << red("Square root of ") << red(to_string(min)) << red(" is invalid!") << endl;
          }
        min++;
      }
  }

int main (int argc, char *argv[])
  {
    cout << "### drill 1 ###" << endl;
    cout << setw(40) << left << "char:" << setw(2) << right << sizeof(char) << endl;
    cout << setw(40) << left << "short:" << setw(2) << right << sizeof(short) << endl;
    cout << setw(40) << left << "int:" << setw(2) << right << sizeof(int) << endl;
    cout << setw(40) << left << "long:" << setw(2) << right << sizeof(long) << endl;
    cout << setw(40) << left << "float:" << setw(2) << right << sizeof(float) << endl;
    cout << setw(40) << left << "double:" << setw(2) << right << sizeof(double) << endl;
    cout << setw(40) << left << "int*:" << setw(2) << right << sizeof(int *) << endl;
    cout << setw(40) << left << "double*:" << setw(2) << right << sizeof(double *) << endl;
    
    cout << endl << "### drill 2 ###" << endl;
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int, 2> d(10, 10);
    Matrix<int, 3> e(10, 10, 10);
    cout << setw(40) << left << "Matrix<int> a(10):" << setw(2) << right << sizeof(a) << endl;
    cout << setw(40) << left << "Matrix<int> b(100):" << setw(2) << right << sizeof(b) << endl;
    cout << setw(40) << left << "Matrix<double> c(10):" << setw(2) << right << sizeof(c) << endl;
    cout << setw(40) << left << "Matrix<int, 2> d(10, 10);" << setw(2) << right << sizeof(d) << endl;
    cout << setw(40) << left << "Matrix<int, 3> e(10, 10, 10):" << setw(2) << right << sizeof(e) << endl;
    
    cout << endl << "### drill 3 ###" << endl;
    cout << a << endl << endl;
    cout << b << endl << endl;
    cout << c << endl << endl;
    cout << d << endl;
//    cout << e << endl; // 3D Matrixes don't have <<
    
    cout << endl << "### drill 4 ###" << endl;
    
    print_sqrt(-10, 10);
    
    cout << endl << "### drill 5 ###" << endl;
    
    Matrix<double> d5(10);
    istringstream iss { "{ 0 1 2 3 4 5 6 7 8 9 }" };
    iss >> d5;
    cout << d5 << endl;
    
    cout << endl << "### drill 6 ###" << endl;
    
    auto n = 11;
    auto m = 11;
    
    Matrix<int, 2> d6(n, m);
    
    for (int ni { 0 } ; ni < n ; ++ni)
      {
        for (int mi { 0 } ; mi < m ; ++mi)
          {
            d6(ni, mi) = ni * mi;
          }
      }
    
    cout << d6 << endl;
    
    cout << endl << "### drill 7 ###" << endl;
    
    Matrix<complex<double>> d7(10);
    
    complex<double> cd;
    
    istringstream iss_d7 { "{(1, 9) (2, 8) (3, 7) (4, 6) (5, 5) (6, 4) (7, 3) (8, 2) (9, 1) (9, 9)}" };
    
    iss_d7 >> d7;
    
    cout << d7 << endl;
    
    complex<double> sum(0, 0);
    for (auto i { 0 } ; i < d7.size() ; ++i)
      {
        sum += d7(i);
      }
    
    cout << "The sum is: " << sum << endl;
    
    cout << endl << "### drill 8 ###" << endl;
    
    Matrix<int, 2> d8(2, 3);
    
    istringstream iss_d8 { "{{1 2 3} {4 5 6}}" };
    
    iss_d8 >> d8;
    
    cout << d8 << endl;
    
    return EXIT_SUCCESS;
  }
