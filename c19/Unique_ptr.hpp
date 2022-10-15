//
// Created by martin on 15-10-22.
//

#pragma once

#include <ostream>

using namespace std;

template < typename T >
class Unique_ptr
  {
  public:
    explicit Unique_ptr (T *ptr) :
        ptr(ptr)
      {
        cout << "Pointer created" << endl;
      }
    
    virtual ~Unique_ptr ()
      {
        cout << "Pointer deleted" << endl;
        delete ptr;
      }
    
    T *operator-> ()
      {
        return ptr;
      }
    
    T *operator* ()
      {
        return ptr;
      }
    
    T *release ()
      {
        auto t = ptr;
        ptr = nullptr;
        return t;
      };
  
  private:
    T *ptr;
  };