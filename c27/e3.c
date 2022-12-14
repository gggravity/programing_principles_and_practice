//
// Created by martin on 10/28/22.
//

#define MAKE_NODE (Link *)make_name
#define PRINT_NODE(node) ((Name *)(node))->name

#include <stdio.h>
#include <stdlib.h>
#include "LL2.h"

typedef struct
{
    struct Link lnk;
    char *name;
} Name;

Name *make_name (char *n)
{
  Name *name = (Name *)malloc (sizeof (Name));
  name->name = n;
  return name;
}

int main (int argc, char *argv[])
{
  int count = 0;
  List names;
  Link *current;
  init (&names);

  push_back (&names, MAKE_NODE ("Norah"));
  push_back (&names, MAKE_NODE ("Annemarie"));
  push_back (&names, MAKE_NODE ("Kris"));
  push_back (&names, MAKE_NODE ("Karl"));
  push_back (&names, MAKE_NODE ("John"));


//  erase (&names, advance (names.first, 1));
  push_front (&names, MAKE_NODE ("Amanda"));

  struct Link *insert_at = advance (names.first, 2);

  printf ("insert_at: %s\n", PRINT_NODE(insert_at));

  insert (&names, insert_at, MAKE_NODE ("Max"));

  current = names.first;
  for (; current != 0 ; current = current->next)
    {
      count++;
      printf ("element %d: %s\n", count, PRINT_NODE(current));
    } // ((Name *)current)->name

  clear (&names);

  return EXIT_SUCCESS;
}

