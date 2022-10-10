//
// Created by martin on 10-10-22.
//

#include <bits/stdc++.h>

using namespace std;

struct Int
    {
        Int ()
            :
            value(0)
          {
          
          }
        
        Int (int value)
            :
            value(value)
          {
          
          }
        
        int value;
        
        bool operator< (const Int &rhs) const
          {
            return value < rhs.value;
          }
        
        bool operator> (const Int &rhs) const
          {
            return rhs < *this;
          }
        
        bool operator<= (const Int &rhs) const
          {
            return !( rhs < *this );
          }
        
        bool operator>= (const Int &rhs) const
          {
            return !( *this < rhs );
          }
        
        bool operator== (const Int &rhs) const
          {
            return value == rhs.value;
          }
        
        bool operator!= (const Int &rhs) const
          {
            return !( rhs == *this );
          }
        
        friend ostream &operator<< (ostream &os, const Int &an_int)
          {
            os << an_int.value;
            return os;
          }
        
        friend const istream &operator>> (istream &is, Int &an_int)
          {
            is >> an_int.value;
            return is;
          }
        
        Int operator+ (const Int &rhs) const
          {
            return { value + rhs.value };
          }
        
        Int operator- (const Int &rhs) const
          {
            return { value - rhs.value };
          }
        
        Int operator* (const Int &rhs) const
          {
            return { value * rhs.value };
          }
        
        Int operator/ (const Int &rhs) const
          {
            return { value / rhs.value };
          }
    };

int main (int argc, char *argv[])
try
  {
    Int i1 { 40 };
    Int i2 { 2 };
    Int i3 { 4 };
    Int i4 { 5 };
    
    cout << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
    
    cout << i1 << " + " << i2 << " + " << i3 << " + " << i4 << " = " << i1 + i2 + i3 + i4 << endl;
    
    cout << i1 << " - " << i2 << " - " << i3 << " - " << i4 << " = " << i1 - i2 - i3 - i4 << endl;
    
    cout << i1 << " * " << i2 << " * " << i3 << " * " << i4 << " = " << i1 * i2 * i3 * i4 << endl;
    
    cout << i1 << " / " << i2 << " / " << i3 << " / " << i4 << " = " << i1 / i2 / i3 / i4 << endl;
    
    cout << "Please enter an integer value: " << endl;
    
    Int i_cin;
    
    cin >> i_cin;
    
    cout << "The entered integer was: " << i_cin << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
