//
// Created by martin on 16-10-22.
//

#pragma once

template < typename Elem >
struct Link
    {
        Link *prev;
        Link *succ;
        Elem val;
    };

template < typename Elem >
class List
  {
  public:
    Link<Elem> *first;
    
    Link<Elem> *last;
    
    class iterator;
    
    iterator begin ();
    
    iterator end ();
    
    iterator insert (iterator p, const Elem &v);
    
    iterator erase (iterator p);
    
    void push_back (const Elem &v);
    
    void push_front (const Elem &v);
    
    void pop_front ();
    
    void pop_back ();
    
    Elem &front ();
    
    Elem &back ();
    
  };

template < typename Elem >
class List<Elem>::iterator
  {
  public:
    explicit iterator (Link<Elem> *p) :
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
    
    Elem &operator* (const iterator &b) const
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
    Link<Elem> *curr;
  };