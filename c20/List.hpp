//
// Created by martin on 16-10-22.
//

#pragma once

template < typename T >
struct Link
    {
        Link *prev;
        Link *succ;
        T val;
    };

template < typename T >
class List
  {
  public:
    explicit List (Link<T> *first = nullptr, Link<T> *last = nullptr) :
        first(first),
        last(last)
      { }
    
    Link<T> *first;
    
    Link<T> *last;
    
    class iterator;
    
    iterator begin ()
      {
        return iterator(first);
      }
    
    iterator end ()
      {
        return iterator(last);
      }
    
    iterator insert (iterator p, const T &v);
    
    iterator erase (iterator p);
    
    void push_back (const T &v);
    
    void push_front (const T &v)
      {
        first = new Link<T>(nullptr, nullptr, v);
      }
    
    void pop_front ();
    
    void pop_back ();
    
    T &front ();
    
    T &back ();
    
  };

template < typename T >
class List<T>::iterator
  {
  public:
    explicit iterator (Link<T> *p) :
        curr { p }
      {
      
      }
    
    iterator &operator++ ()
      {
        curr->succ;
        return *this;
      }
    
    iterator &operator-- ()
      {
        curr->prev;
        return *this;
      }
    
    T &operator* (const iterator &b) const
      {
        return curr->val;
      }
    
    bool operator== (const iterator &b) const
      {
        return curr == b.curr;
      }
    
    bool operator!= (const iterator &b) const
      {
        return curr != b.curr;
      }
  
  private:
    Link<T> *curr;
  };

template < class Iterator >
Iterator high (Iterator first, Iterator last)
  {
    Iterator high = first;
    for (Iterator p = first ; p != last ; ++p)
      {
        if (*high< * p)
          {
            high = p;
          }
      }
    return high;
  }