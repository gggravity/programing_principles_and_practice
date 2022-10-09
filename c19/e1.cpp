//
// Created by martin on 09-10-22.
//

#include <bits/stdc++.h>

using namespace std;

template < typename T, typename U >
void f (vector<T> &v, vector<U> &u)
  {
    for (size_t i { 0 } ; i < v.size() ; ++i)
      {
        v[i] += u[i];
      }
  }

template < typename T >
void print (vector<T> &v)
  {
    for (auto const &elem : v)
      {
        cout << setw(3) << elem;
      }
    cout << endl;
  }

int main (int argc, char *argv[])
try
  {
    vector<int> v1 { 1, 2, 3, 4, 5 };
    vector<int> v2 { 6, 7, 8, 9, 8, 7, 6 };
    
    cout << "-----------------------" << endl;
    print(v1);
    print(v2);
    
    f(v1, v2);
    
    cout << "-----------------------" << endl;
    print(v1);
    print(v2);
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
