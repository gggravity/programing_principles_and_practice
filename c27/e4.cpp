//
// Created by martin on 10/28/22.
//

#include "../std_lib.h"
#include "Linked_list.hpp"

using Link = Linked_list<string>::Link;

int main (int argc, char *argv[])
{
  Linked_list<string> names;

  names.push_back (new Link ("Norah"));
  names.push_back (new Link ("Annemarie"));
  names.push_back (new Link ("Kris"));
  names.push_back (new Link ("Karl"));
  names.push_back (new Link ("john"));

//  erase (&names, advance (names.first, 1));
  names.push_front (new Link ("Ananda"));

  auto insert_at = names.advance (names.first, 2);

  cout << "insert_at: " << *insert_at << endl;

  names.insert (insert_at, new Link ("Max"));

  auto current = names.first;
  for (int count { 0 } ; current != nullptr ; current = current->next, ++count)
    {
      cout << "element " << count << " : " << *current << endl;
    }

  return EXIT_SUCCESS;
}

