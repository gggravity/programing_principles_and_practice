//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>
#include "boost/lexical_cast.hpp"

using namespace std;

template < typename T >
struct Debug_vector : std::vector<T>
    {
        using size_type = typename std::vector<T>::size_type;
        
        using std::vector<T>::vector;    // inheriting constructor
        
        friend ostream &operator<< (ostream &os, const Debug_vector &v)
          {
            cout << "{ ";
            for (auto iter { v.begin() } ; iter != v.end() ; ++iter)
              {
                iter != v.end() - 1 ? os << *iter << ", " : os << *iter;
              }
            cout << " }";
            return os;
          }
        
        friend istream &operator>> (istream &is, vector<T> &v)
          {
            string str;
            
            while (is >> str)
              {
                v.push_back(boost::lexical_cast<T>(str));
              }
            
            return is;
          }
    };

#define vector Debug_vector

int main (int argc, char *argv[])
try
  {
    auto double_data = vector<double> { 123.1, 123.4, 213.9, 321.4, 423.0, 543.0, 324.4, 123.6 };
    auto int_data = vector<int> { 123, 123, 213, 321, 423, 543, 324, 123 };
    auto string_data = vector<string> { "Howdy", "Hans", "Gretha", "TEST" };
    
    cout << double_data << endl;
    cout << int_data << endl;
    cout << string_data << endl;
    
    cout << "------------------------------------------------------" << endl;
    
    istringstream iss_double { "12321.32 213213.44" };
    iss_double >> double_data;
    cout << double_data << endl;
    
    istringstream iss_int { "1 2 3 4 5 6 7 8 9 0" };
    iss_int >> int_data;
    cout << int_data << endl;
    
    istringstream iss_string { "HELLO WORLD" };
    iss_string >> string_data;
    cout << string_data << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

