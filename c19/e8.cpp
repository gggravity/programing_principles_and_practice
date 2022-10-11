//
// Created by martin on 11-10-22.
//

#include <bits/stdc++.h>
#include "Vector.hpp"

using namespace std;

//template < typename T >
//void print (const vector<T> &v, int width = 3)
//  {
//    for (auto const &elem : v)
//      {
//        cout << setw(width) << elem;
//      }
//    cout << endl;
//  }
//
//template < typename T >
//class allocator
//  {
//  public:
//    T *allocate (int n);
//
//    void deallocate (T *p, int n);
//
//    void construct (T *p, const T &v);
//
//    void destroy (T *p);
//  };

int main (int argc, char *argv[])
try
  {
    
    Vector<double> v;
    
    v.push_back(12.3);
    v.push_back(32.1);
    v.push_back(111.1);
    v.push_back(222.2);
    v.push_back(333.3);
    
    for (auto i { 0 } ; i < v.size() ; ++i)
      {
        cout << v[i] << " " << endl;
      }
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
