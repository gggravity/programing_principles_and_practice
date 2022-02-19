#include "Link.h"

#include <utility>

Link::Link (string v, Link *p = nullptr, Link *s = nullptr)
    : value { std::move(v) },
      prev { p },
      succ { s }
  {

  }

Link *Link::insert (Link *n)
  {
    return nullptr;
  }

Link *Link::add (Link *n)
  {

  }

Link *Link::erase ()
  {
    return nullptr;
  }

Link *Link::find (const string &s) const
  {
    return nullptr;
  }

Link *Link::advance (int n) const
  {
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