//
// Created by martin on 10/28/22.
//

#include "../std_lib.h"
#include "Linked_list.hpp"

using Link = Linked_list<string>::Link;

int main (int argc, char *argv[])
{
  int count = 0;
  Linked_list<string> names;
  Linked_list<string>::Link *current;

  auto norah = Link ("Norah");
  auto annemarie = Link ("Annemarie");
  auto kris = Link ("Kris");
  auto karl = Link ("Karl");
  auto john = Link ("john");

  names.push_back (&norah);
  names.push_back (&annemarie);
  names.push_back (&kris);
  names.push_back (&karl);
  names.push_back (&john);


//  erase (&names, advance (names.first, 1));
  auto amanda = Linked_list<string>::Link ("Ananda");
  names.push_front (&amanda);

  auto insert_at = names.advance (names.first, 2);

  cout << "insert_at: " << *insert_at << endl;

  auto max = Linked_list<string>::Link ("Max");
  names.insert (insert_at, &max);

  current = names.first;
  for (; current != nullptr ; current = current->next)
    {
      count++;
      cout << "element " << count << " : " << *current << endl;
    }

  return EXIT_SUCCESS;
}

