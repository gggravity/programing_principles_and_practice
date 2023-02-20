//
// Created by martin on 10-10-22.
//

#include <bits/stdc++.h>

using namespace std;

template < typename T >
struct Number
    {
        Number ()
            :
            value(0)
          {
          
          }
        
        explicit Number (T value)
            :
            value(value)
          {
          
          }
        
        T value;
        
        bool operator< (const Number &rhs) const
          {
            return value < rhs.value;
          }
        
        bool operator> (const Number &rhs) const
          {
            return rhs < *this;
          }
        
        bool operator<= (const Number &rhs) const
          {
            return !( rhs < *this );
          }
        
        bool operator>= (const Number &rhs) const
          {
            return !( *this < rhs );
          }
        
        bool operator== (const Number &rhs) const
          {
            return value == rhs.value;
          }
        
        bool operator!= (const Number &rhs) const
          {
            return !( rhs == *this );
          }
        
        friend ostream &operator<< (ostream &os, const Number &number)
          {
            os << number.value;
            return os;
          }
        
        friend const istream &operator>> (istream &is, Number &number)
          {
            is >> number.value;
            return is;
          }
        
        Number operator+ (const Number &rhs) const
          {
            return Number { value + rhs.value };
          }
        
        Number operator- (const Number &rhs) const
          {
            return Number { value - rhs.value };
          }
        
        Number operator* (const Number &rhs) const
          {
            return Number { value * rhs.value };
          }
        
        Number operator/ (const Number &rhs) const
          {
            return Number { value / rhs.value };
          }
    };

template < typename T, typename U >
vector<T> f (const vector<T> &vt, const vector<U> &vu)
  {
    vector<T> v;
    
    for (size_t i { 0 } ; i < vt.size() ; ++i)
      {
        v.push_back(vt[i] * vu[i]);
      }
    return v;
  }

template < typename T >
void print (const vector<T> &v, int width = 3)
  {
    for (auto const &elem : v)
      {
        cout << setw(width) << elem;
      }
    cout << endl;
  }

int main (int argc, char *argv[])
try
  {
    vector<Number<int>> vni1 { Number<int>(1), Number<int>(2), Number<int>(3) };
    vector<Number<int>> vni2 { Number<int>(3), Number<int>(2), Number<int>(1) };
    
    auto vni3 = f(vni1, vni2);
    
    print(vni3);
    
    vector<Number<double>> vnd1 { Number<double>(1.1), Number<double>(2.2), Number<double>(3.3) };
    vector<Number<double>> vnd2 { Number<double>(3.3), Number<double>(2.2), Number<double>(11.1) };
    
    auto vnd3 = f (vnd1, vnd2);
    
    print(vnd3, 6);
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
