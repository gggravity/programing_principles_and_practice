//
// Created by martin on 10/28/22.
//

#include <stdlib.h>
#include <assert.h>
#include "LL2.h"

void init (List *list)
{
  assert(list);
  list->first = list->last = 0;
}

List *crate ()
{
  List *list = (List *)malloc (sizeof (List));
  init (list);
  return list;
}

void clear (List *list)
{
  assert(list);
  Link *current = list->first;
  while (current)
    {
      Link *next = current->next;
      free (current);
      current = next;
    }
  list->first = list->last = 0;
}

void destroy (List *list)
{
  assert(list);
  clear (list);
  free (list);
}

void push_back (List *list, Link *new_node)
{
  assert(list);
  Link *last = list->last;
  if (last)
    {
      last->next = new_node;
      new_node->prev = last;
    }
  else
    {
      list->first = new_node;
      new_node->prev = 0;
    }
  list->last = new_node;
  new_node->next = 0;
}

void push_front (List *list, Link *new_node)
{
  new_node->next = list->first;
  list->first = new_node;
}

void insert (List *list, Link *previous_node, Link *new_node)
{
  new_node->next = previous_node->next;
  previous_node->next = new_node;

  Link *next_node = previous_node->next;
  new_node->prev = next_node->prev;
  new_node->prev = new_node;
}

Link *erase (List *list, Link *new_node)
{
  assert(list);
  if (new_node == 0)
    {
      return 0;
    }
  if (new_node == list->first)
    {
      if (new_node->next)
        {
          list->first = new_node->next;
          new_node->next->prev = 0;
          return new_node->next;
        }
      else
        {
          list->first = list->last = 0;
          return 0;
        }
    }
  else if (new_node == list->last)
    {
      if (new_node->prev)
        {
          list->last = new_node->prev;
          new_node->prev->next = 0;
        }
      else
        {
          list->first = list->last = 0;
          return 0;
        }
    }
  else
    {
      new_node->next->prev = new_node->prev;
      new_node->prev->next = new_node->next;
      return new_node->next;
    }
}

Link *advance (Link *node, int n)
{
  for (int i = 0 ; i < n ; ++i)
    {
      node = node->next;
    }
  return node;
}
