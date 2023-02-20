//
// Created by martin on 10/28/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "LL.h"

void init (struct List *list)
{
  assert(list);
  list->first = list->last = 0;
}

struct List *crate ()
{
  struct List *list = (struct List *)malloc (sizeof (struct List));
  init (list);
  return list;
}

void clear (struct List *list)
{
  assert(list);
  struct Link *current = list->first;
  while (current)
    {
      struct Link *next = current->next;
      free (current);
      current = next;
    }
  list->first = list->last = 0;
}

void destroy (struct List *list)
{
  assert(list);
  clear (list);
  free (list);
}

void push_back (struct List *list, struct Link *new_node)
{
  assert(list);
  struct Link *last = list->last;
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

void push_front (struct List *list, struct Link *new_node)
{
  new_node->next = list->first;
  list->first = new_node;
}

void insert (struct List *list, struct Link *previous_node, struct Link *new_node)
{
  new_node->next = previous_node->next;
  previous_node->next = new_node;

  struct Link *next_node = previous_node->next;
  new_node->prev = next_node->prev;
  new_node->prev = new_node;
}

struct Link *erase (struct List *list, struct Link *new_node)
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

struct Link *advance (struct Link *node, int n)
{
  for (int i = 0 ; i < n ; ++i)
    {
      node = node->next;
    }
  return node;
}
