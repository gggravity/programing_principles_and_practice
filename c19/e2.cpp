//
// Created by martin on 09-10-22.
//

#include <bits/stdc++.h>

using namespace std;

template < typename T, typename U >
vector<T> f (const vector<T> &vt, const vector<U> &vu)
  {
    vector<T> v;
    
    for (size_t i { 0 } ; i < vt.size() ; ++i)
      {
        v.push_back(vt[i] * vu[i]);
      }
    if (vu.size() > vt.size())
      {
        for (size_t i { 0 } ; i < ( vu.size() - vt.size() ) ; ++i)
          {
            v.push_back(0);
          }
      }
    
    return v;
  }

template < typename T >
void print (const vector<T> &v)
  {
    for (auto const &elem : v)
      {
        cout << setw(5) << elem;
      }
    cout << endl;
  }

int main (int argc, char *argv[])
try
  {
    vector<double> v1 { 1.1, 2.2, 3.3, 4.4, 5.5 };
    vector<int> v2 { 6, 7, 8, 9, 8, 7, 6 };
    
    cout << "-----------------------" << endl;
    print(v1);
    print(v2);
    
    auto v { f(v1, v2) };
    
    cout << "-----------------------" << endl;
    print(v);
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
