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

int main (int argc, char *argv[])
try
  {
    Number n1 { 44.4 };
    Number n2 { 2.2 };
    Number n3 { 4.4 };
    Number n4 { 5.5 };
    
    cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    
    cout << n1 << " + " << n2 << " + " << n3 << " + " << n4 << " = " << n1 + n2 + n3 + n4 << endl;
    
    cout << n1 << " - " << n2 << " - " << n3 << " - " << n4 << " = " << n1 - n2 - n3 - n4 << endl;
    
    cout << n1 << " * " << n2 << " * " << n3 << " * " << n4 << " = " << n1 * n2 * n3 * n4 << endl;
    
    cout << n1 << " / " << n2 << " / " << n3 << " / " << n4 << " = " << n1 / n2 / n3 / n4 << endl;
    
    cout << "Please enter a number: " << endl;
    
    Number<int> number;
    
    cin >> number;
    
    cout << "The number was: " << number << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    
    return EXIT_FAILURE;
  }
