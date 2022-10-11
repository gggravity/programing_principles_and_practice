//
// Created by martin on 11-10-22.
//

#pragma once

template < typename T >
class Vector
  {
  public:
    Vector () :
        sz { 0 },
        elem { nullptr },
        space { 0 }
      {
      
      }
    
    explicit Vector (size_t s) :
        sz { s },
        elem { new double[s] },
        space { s }
      {
        for (int i = 0 ; i < sz ; ++i)
          {
            elem[i] = 0;
          }
      }
    
    Vector (const Vector &v)
      {
      
      }
    
    Vector &operator= (const Vector &v)
      {
        if (this == &v)
          {
            return *this;
          }
        
        if (v.sz <= space)
          {
            for (int i = 0 ; i < v.sz ; ++i)
              {
                elem[i] = v.elem[i];
              }
            sz = v.sz;
            return *this;
          }
        
        auto *p = new double[v.sz];
        for (int i = 0 ; i < v.sz ; ++i)
          {
            p[i] = v.elem[i];
            delete[] elem;
            space = sz = v.sz;
            elem = p;
            return *this;
          }
      }
    
    Vector (Vector &&v)
      {
      
      }
    
    Vector &operator= (Vector &&v)
      {
      
      }
    
    ~Vector ()
      {
        delete[] elem;
      }
    
    T &operator[] (size_t n)
      {
        return elem[n];
      }
    
    const T &operator[] (size_t n) const
      {
        return elem[n];
      }
    
    void push_back (T t)
      {
        if (space == 0)
          {
            reserve(8);
          }
        else if (sz == space)
          {
            reserve(2 * space);
          }
        elem[sz] = t;
        ++sz;
      }
    
    void resize (int new_size)
      {
        reserve(new_size);
        for (int i = sz ; i < new_size ; ++i)
          {
            elem[i] = 0;
          }
        sz = new_size;
      }
    
    void reserve (int new_alloc)
      {
        if (new_alloc <= space)
          {
            return;
          }
        auto *p = new double[new_alloc];
        for (int i = 0 ; i < sz ; ++i)
          {
            p[i] = elem[i];
          }
        delete[] elem;
        elem = p;
        space = new_alloc;
      }
    
    [[nodiscard]] size_t capacity () const
      {
        return space;
      }
    
    [[nodiscard]] size_t size () const
      {
        return sz;
      }
  
  private:
    size_t sz;
    T *elem;
    size_t space;
    
  };