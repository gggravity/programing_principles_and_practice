//
// Created by martin on 11-10-22.
//

#include <bits/stdc++.h>
#include <ostream>
#include "Vector.hpp"

#define vector Vector

struct Test
    {
        int one;
        int two;
        
        Test (int one, int two) :
            one(one),
            two(two)
          {
          
          }
        
        friend std::ostream &operator<< (std::ostream &os, const Test &test)
          {
            os << "{ " << test.one << ", " << test.two << " }";
            return os;
          }
    };

using namespace std;

template < typename T >
void print (const vector<T> &v, int width = 3)
  {
    for (size_t i { 0 } ; i < v.size() ; ++i)
      {
        cout << setw(width) << v[i];
      }
    cout << endl;
  }

int main (int argc, char *argv[])
try
  {
    Debug_vector<double> vd;
    
    vd.push_back(123.123);
    vd.push_back(321.321);
    vd.push_back(222.222);
    vd.push_back(12.12);
    vd.push_back(33333.333);
    
    print(vd, 8);
    
    Debug_vector<Test> vt;
    
    vt.push_back({ 1, 2 });
    vt.push_back({ 3, 4 });
    vt.push_back({ 5, 6 });
    vt.push_back({ 7, 8 });
    vt.push_back({ 9, 0 });
    
    print(vt, 8);
    
    Debug_vector<Test> v_equal;
    
    v_equal = vt;

    print(v_equal, 8);

    /* don't work for classes with constructors, see page 1193 for more info. */

//        Vector<string> vs;
//
//    vs.push_back("Hello");
//    vs.push_back("World");
//    vs.push_back("C");
//    vs.push_back("C++");
//    vs.push_back("C/C++");
//
//    print(vs, 12);
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
