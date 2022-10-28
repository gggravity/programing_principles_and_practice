//
// Created by martin on 10/28/22.
//

#pragma once

#include <ostream>
#include "../std_lib.h"

template < typename T >
struct Linked_list
{
    struct Link
    {
        explicit Link (T content) :
            content (content)
        { }

        Link *prev;
        Link *next;
        T content;

        friend ostream &operator<< (ostream &os, const Link &link)
        {
          os << link.content;
          return os;
        }
    };

    Linked_list () :
        first { nullptr },
        last { nullptr },
        current { nullptr }
    {

    }

    virtual ~Linked_list () = default;
//    void clear (List *list);
//    void destroy (List *list);

    void push_back (Link *new_node)
    {
      auto new_last = last;
      if (new_last)
        {
          new_last->next = new_node;
          new_node->prev = new_last;
        }
      else
        {
          first = new_node;
          new_node->prev = nullptr;
        }
      last = new_node;
      new_node->next = nullptr;
    }
    void push_front (Link *new_node)
    {
      new_node->next = first;
      first = new_node;
    }

    void insert (Link *previous_node, Link *new_node)
    {
      new_node->next = previous_node->next;
      previous_node->next = new_node;

      Link *next_node = previous_node->next;
      new_node->prev = next_node->prev;
      new_node->prev = new_node;
    }
    Link *erase (Link *new_node)
    {
      if (new_node == nullptr)
        {
          return nullptr;
        }
      if (new_node == first)
        {
          if (new_node->next)
            {
              first = new_node->next;
              new_node->next->prev = nullptr;
              return new_node->next;
            }
          else
            {
              first = last = nullptr;
              return nullptr;
            }
        }
      else if (new_node == last)
        {
          if (new_node->prev)
            {
              last = new_node->prev;
              new_node->prev->next = nullptr;
            }
          else
            {
              first = last = nullptr;
              return nullptr;
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

    Link *first;
    Link *last;
    Link *current;
};


