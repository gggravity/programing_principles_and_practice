//
// Created by martin on 10/28/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

struct Name
{
    struct Link lnk;
    char *name;
};

struct Name *make_name (char *n)
{
  struct Name *name = (struct Name *)malloc (sizeof (struct Name));
  name->name = n;
  return name;
}

int main (int argc, char *argv[])
{
  int count = 0;
  struct List names;
  struct Link *current;
  init (&names);

  push_back (&names, (struct Link *)make_name ("Norah"));
  push_back (&names, (struct Link *)make_name ("Annemarie"));
  push_back (&names, (struct Link *)make_name ("Kris"));
  push_back (&names, (struct Link *)make_name ("Karl"));
  push_back (&names, (struct Link *)make_name ("John"));


//  erase (&names, advance (names.first, 1));
  push_front (&names, (struct Link *)make_name ("Amanda"));

  struct Link *insert_at = advance (names.first, 2);

  printf ("insert_at: %s\n", ((struct Name *)insert_at)->name);

  insert (&names, insert_at, (struct Link *)make_name ("Max"));

  current = names.first;
  for (; current != 0 ; current = current->next)
    {
      count++;
      printf ("element %d: %s\n", count, ((struct Name *)current)->name);
    }

  clear (&names);

  return EXIT_SUCCESS;
}

