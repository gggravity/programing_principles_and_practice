#include "God.h"

God::God (const string &name, const string &mythology, const string &vehicle, const string &weapon, God *p, God *s)
    : name { name },
      mythology { mythology },
      vehicle { vehicle },
      weapon { weapon },
      prev { p },
      succ { s }
  {

  }

God *God::insert (God *n)
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

God *God::add (God *n)
  {

  }

God *God::erase ()
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

const God *God::find (const string &s) const
  {
    auto p = this;
    while (p)
      {
        if (p->name == s)
          {
            return p;
          }
        p = p->succ;
      }
    return nullptr;
  }

God *God::find (const string &s)
  {
    auto p = this;
    while (p)
      {
        if (p->name == s)
          {
            return p;
          }
        p = p->succ;
      }
    return nullptr;
  }

God *God::advance (int n) const
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

God *God::next () const
  {
    return succ;
  }

God *God::previous () const
  {
    return prev;
  }

void print_all (God *p)
  {
    while (p)
      {
        cout << "Name: " << p->name
             << ", Mythology: " << p->mythology
             << ", Vehicle: " << p->vehicle
             << ", Weapon: " << p->weapon << endl;
        p = p->next();
      }
  }