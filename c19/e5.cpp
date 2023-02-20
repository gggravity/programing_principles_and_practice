//
// Created by martin on 10-10-22.
//

#include <bits/stdc++.h>

using namespace std;

struct Number
    {
        Number ()
            :
            value(0)
          {
          
          }
        
        Number (int value)
            :
            value(value)
          {
          
          }
        
        int value;
        
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
        
        friend ostream &operator<< (ostream &os, const Number &an_int)
          {
            os << an_int.value;
            return os;
          }
        
        friend const istream &operator>> (istream &is, Number &an_int)
          {
            is >> an_int.value;
            return is;
          }
        
        Number operator+ (const Number &rhs) const
          {
            return { value + rhs.value };
          }
        
        Number operator- (const Number &rhs) const
          {
            return { value - rhs.value };
          }
        
        Number operator* (const Number &rhs) const
          {
            return { value * rhs.value };
          }
        
        Number operator/ (const Number &rhs) const
          {
            return { value / rhs.value };
          }
    };

int main (int argc, char *argv[])
try
  {
    Number i1 { 40 };
    Number i2 { 2 };
    Number i3 { 4 };
    Number i4 { 5 };
    
    cout << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
    
    cout << i1 << " + " << i2 << " + " << i3 << " + " << i4 << " = " << i1 + i2 + i3 + i4 << endl;
    
    cout << i1 << " - " << i2 << " - " << i3 << " - " << i4 << " = " << i1 - i2 - i3 - i4 << endl;
    
    cout << i1 << " * " << i2 << " * " << i3 << " * " << i4 << " = " << i1 * i2 * i3 * i4 << endl;
    
    cout << i1 << " / " << i2 << " / " << i3 << " / " << i4 << " = " << i1 / i2 / i3 / i4 << endl;
    
    cout << "Please enter an integer value: " << endl;
    
    Number i_cin;
    
    cin >> i_cin;
    
    cout << "The entered integer was: " << i_cin << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
