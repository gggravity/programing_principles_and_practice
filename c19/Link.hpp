#pragma once

#include <bits/stdc++.h>

#include <utility>

using namespace std;

template < typename T >
struct Link
  {
    T value;
    
    explicit Link (T v, Link *p = nullptr, Link *s = nullptr)
        :
        value { std::move(v) },
        prev { p },
        succ { s }
      {
      
      }
    
    Link *insert (Link *n)
      {
        if (n == nullptr)
          {
            return this;
          }
        
        n->succ = this;
        
        if (prev)
          {
            prev->succ = n;
          }
        
        n->prev = prev;
        prev = n;
        
        return n;
      }
    
    Link *add (Link *n)
      {
        value = n->value;
        return this;
      }
    
    Link *erase ()
      {
        if (succ)
          {
            succ->prev = prev;
          }
        if (prev)
          {
            prev->succ = succ;
          }
        return succ;
      }
    
    [[nodiscard]] const Link *find (const T &s) const
      {
        auto p = this;
        while (p)
          {
            if (p->value == s)
              {
                return p;
              }
            p = p->succ;
          }
        return nullptr;
      }
    
    Link *find (const T &s)
      {
        auto p = this;
        while (p)
          {
            if (p->value == s)
              {
                return p;
              }
            p = p->succ;
          }
        return nullptr;
      }
    
    [[nodiscard]] Link *advance (int n) const
      {
        auto p = this;
        if (p == nullptr)
          {
            return nullptr;
          }
        if (0 < n)
          {
            while (n++)
              {
                if (p->succ == nullptr)
                  {
                    return nullptr;
                  }
                p = p->succ;
              }
          }
        else if (n < 0)
          {
            while (n++)
              {
                if (p->prev == nullptr)
                  {
                    return nullptr;
                  }
                p = p->prev;
              }
          }
        return nullptr;
      }
    
    [[nodiscard]] Link *next () const
      {
        return succ;
      }
    
    [[nodiscard]] Link *previous () const
      {
        return prev;
      }
  
  private:
    Link *prev;
    Link *succ;
    
  };

