#pragma once

#include <bits/stdc++.h>
#include "../terminal_colors/terminal_colors.h"
#include "boost/lexical_cast.hpp"

using namespace std;
using namespace terminal_colors;

void print_line_break (size_t n = 80)
  {
    for (size_t i { 0 } ; i < n ; ++i)
      {
        printf("-");
      }
    printf("\n");
  }

void header (const string &header, bool first = false)
  {
    if (!first)
      {
        putchar('\n');
      }
    
    printf("### %s ###", header.c_str());
    
//    for (auto i { header.size() + 5 } ; i <= 80 ; ++i)
//      {
//        putchar('#');
//      }
    
    printf("\n\n");
  }

vector<string> split (const string &text, char delimiter = ' ')
  {
    vector<string> words { };
    
    istringstream iss { text };
    string s;
    while (getline(iss, s, delimiter))
      {
        words.push_back(s);
      }
    
    return words;
  }
  
// random number generators. See 24.7.

inline std::default_random_engine &get_rand ()
  {
    static std::default_random_engine ran;    // note: not thread_local
    return ran;
  }

inline void seed_randint (int s)
  {
    get_rand().seed(s);
  }

inline int randint (int min, int max)
  {
    return std::uniform_int_distribution<> { min, max }(get_rand());
  }

inline int randint (int max)
  {
    return randint(0, max);
  }

template < typename Container >
void print (Container container)
  {
    cout << "{ ";
    for (auto iter { container.begin() } ; iter != container.end() ; ++iter)
      {
        auto last = container.end();
        last--;
        if (iter != last)
          {
            cout << *iter << ", ";
          }
        else
          {
            cout << *iter;
          }
      }
    cout << " }" << endl;
  }

template < typename T >
struct Debug_vector : std::vector<T>
    {
        using size_type = typename std::vector<T>::size_type;
        
        using std::vector<T>::vector;    // inheriting constructor
        
        T &operator[] (unsigned int i) // rather than return at(i);
          {
            if (i < 0 || this->size() <= i)
              {
                throw out_of_range(to_string(i));
              }
            return std::vector<T>::operator[](i);
          }
        
        const T &operator[] (unsigned int i) const
          {
            if (i < 0 || this->size() <= i)
              { throw out_of_range(to_string(i)); }
            return std::vector<T>::operator[](i);
          }
        
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

template < typename Container1, typename Container2 >
// requires Container<C>()
void copy (Container1 &from_container, Container2 &to_container)
  {
    std::copy(from_container.begin(), from_container.end(), to_container.begin());
  }

template < typename Container >
// requires Container<C>()
void sort (Container &c)
  {
    std::sort(c.begin(), c.end());
  }

template < typename Container, typename Predicate >
// requires Container<C>() && Binary_Predicate<Value_type<C>>()
void sort (Container &c, Predicate predicate)
  {
    std::sort(c.begin(), c.end(), predicate);
  }

template < typename Container, typename Value >
// requires Container<C>() && Equality_comparable<C,Val>()
auto find (Container &c, Value value)
  {
    return std::find(c.begin(), c.end(), value);
  }

template < typename Container, typename Predicate >
// requires Container<C>() && Predicate<Predicate,Value_type<C>>()
auto find_if (Container &c, Predicate predicate)
  {
    return std::find_if(c.begin(), c.end(), predicate);
  }

#define vector Debug_vector