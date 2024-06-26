//
// Created by martin on 10/22/22.
//

#include "../std_lib.h"
#include "Matrix.h"
#include "MatrixIO.h"

//using namespace Numeric_lib;

typedef Numeric_lib::Matrix<double, 2> Matrix;
typedef Numeric_lib::Matrix<double, 1> Vector;

void classical_elimination (Matrix A, Vector b)
  {
    using namespace Numeric_lib;
    const Index n = A.dim1();
    
    for (Index j { 0 } ; j < n - 1 ; ++j)
      {
        const double pivot = A(j, j);
        if (pivot == 0)
          {
            throw runtime_error("classical_elimination" + to_string(j));
          }
        
        for (Index i = j + 1 ; i < n ; ++i)
          {
            const double mult = A(i, j) / pivot;
            A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
            b(i) -= mult * b(j);
          }
      }
  }

Vector back_substitution (const Matrix &A, const Vector &b)
  {
    using namespace Numeric_lib;
    const Index n = A.dim1();
    Vector x(n);
    
    for (Index i = n - 1 ; i >= 0 ; --i)
      {
        double s = b(i) - dot_product(A[i].slice(i + 1), x.slice(i + 1));
        
        if (double m = A(i, i))
          {
            x(i) = s / m;
          }
        else
          {
            throw runtime_error("back_substitution failed");
          }
      }
    return x;
  }

Vector classical_gaussian_elimination (Matrix A, Vector b)
  {
    classical_elimination(A, b);
    return back_substitution(A, b);
  }

Vector random_vector (Numeric_lib::Index n)
  {
    Vector v(n);
    default_random_engine ran { };
    uniform_real_distribution<> ureal { 0, 1000 };
    
    for (Numeric_lib::Index i = 0 ; i < n ; ++i)
      {
        v(i) = ureal(ran);
      }
    return v;
  }

Matrix random_matrix (Numeric_lib::Index n)
  {
    Matrix m(n, n);
    default_random_engine ran { };
    uniform_real_distribution<> ureal { 0, 100 };
    
    for (Numeric_lib::Index i = 0 ; i < n ; ++i)
      {
        for (Numeric_lib::Index j = 0 ; j < n ; ++j)
          {
            m(i, j) = ureal(ran);
          }
      }
    return m;
  }

Vector operator* (const Matrix &m, const Vector &u)
  {
    const Numeric_lib::Index n = m.dim1();
    Vector v(n);
    for (Numeric_lib::Index i = 0 ; i < n ; ++i)
      {
        v(i) = Numeric_lib::dot_product(m[i], u);
      }
    return v;
  }

int main (int argc, char *argv[])
  {
    int n { 2 };
    Matrix A = random_matrix(n);
    Vector b = random_vector(n);
    
    cout << "A = " << A << endl;
    cout << "b = " << b << endl;
    
    try
      {
        Vector x = classical_gaussian_elimination(A, b);
        cout << "classical elimination solution is x = " << x << endl;
        Vector v = A * x;
        cout << "A*x = " << v << endl;
      }
    catch (const exception &e)
      {
        cerr << e.what() << endl;
      }
    
    return EXIT_SUCCESS;
  }
