#include "Link.h"

#include <utility>

Link::Link (const string &v, Link *p, Link *s)
    : value { v },
      prev { p },
      succ { s }
  {

  }

Link *Link::insert (Link *n)
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

Link *Link::add (Link *n)
  {

  }

Link *Link::erase ()
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

const Link *Link::find (const string &s) const
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

Link *Link::advance (int n) const
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

Link *Link::next () const
  {
    return succ;
  }

Link *Link::previous () const
  {
    return prev;
  }

void print_all (Link *p)
  {
    cout << "{ ";
    while (p)
      {
        cout << p->value;
        p = p->next();
        if (p)
          { std::cout << ", "; }
      }
    cout << " }\n";
  }