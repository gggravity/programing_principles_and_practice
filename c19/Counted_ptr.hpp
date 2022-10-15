//
// Created by martin on 15-10-22.
//

#pragma once

#include <bits/stdc++.h>

using namespace std;

template < typename T >
class Counted_ptr
  {
  public:
    explicit Counted_ptr (T *ptr) :
        ptr(ptr)
      {
        ++*count;
        cout << "Creating pointer" << endl;
        cout << "count: " << *count << endl;
      }
    
    virtual ~Counted_ptr ()
      {
        cout << "Deleting pointer" << endl;
        if (*count == 0)
          {
            delete ptr;
            delete count;
          }
        else
          {
            --*count;
            cout << "count: " << *count << endl;
          }
      }
    
    T *operator-> ()
      {
        return ptr;
      }
    
    T &operator* ()
      {
        return *ptr;
      }
    
    T *release ()
      {
        auto t = ptr;
        ptr = nullptr;
        --*count;
        return t;
      };
    
    [[nodiscard]] int &get_count () const
      {
        return *count;
      }
    
    Counted_ptr (Counted_ptr &other)
      {
        cout << "Copy constructor called " << endl;
        ptr = other.ptr;
        count = other.count;
        ++*count;
      }
    
    Counted_ptr &operator= (const Counted_ptr &other)
      {
        cout << "Assignment operator called " << endl;
        
        if (this == &other)
          {
            return *this;
          }
        
        ptr = other.ptr;
        count = other.count;
        
        return *this;
      }
  
  private:
    T *ptr;
    int *count = new int { 0 };
  };