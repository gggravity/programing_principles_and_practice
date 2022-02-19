#pragma once

#include <bits/stdc++.h>

using namespace std;

class Link
      {
      public:
            string value;

            Link (string v, Link *p = nullptr, Link *s = nullptr);

            Link *insert (Link *n);

            Link *add (Link *n);

            Link *erase ();

            Link *find (const string &s) const;

            Link *advance (int n) const;

            Link *next () const;

            Link *previous () const;

      private:
            Link *prev;
            Link *succ;

      };


