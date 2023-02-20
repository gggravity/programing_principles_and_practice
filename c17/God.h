#pragma once

#include <bits/stdc++.h>

using namespace std;

class God
      {
      public:
            string name;
            string mythology;
            string vehicle;
            string weapon;

            God (const string &name, const string &mythology, const string &vehicle, const string &weapon, God *p = nullptr, God *s = nullptr);

            God *insert (God *n);

            God *add (God *n);

            God *erase ();

            [[nodiscard]] const God *find (const string &s) const;

            God *find (const string &s);

            [[nodiscard]] God *advance (int n) const;

            [[nodiscard]] God *next () const;

            [[nodiscard]] God *previous () const;

      private:
            God *prev;
            God *succ;

      };

void print_all (God *p);