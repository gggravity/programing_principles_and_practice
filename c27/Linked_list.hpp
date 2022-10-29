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

    virtual ~Linked_list ()
    {
      auto ptr = first;
      while (ptr)
        {
          auto next = ptr->next;
          delete (ptr);
          ptr = next;
        }
    }

    void push_back (Link *node)
    {
      auto old_last = last;
      if (old_last)
        {
          old_last->next = node;
          node->prev = old_last;
        }
      else
        {
          first = node;
          node->prev = nullptr;
        }
      last = node;
      node->next = nullptr;
    }
    void push_front (Link *node)
    {
      node->next = first;
      first = node;
    }

    void insert (Link *node_to_insert_after, Link *node)
    {
      node->next = node_to_insert_after->next;
      node_to_insert_after->next = node;

      Link *next_node = node_to_insert_after->next;
      node->prev = next_node->prev;
      node->prev = node;
    }

    Link *erase (Link *node)
    {
      if (node == nullptr)
        {
          return nullptr;
        }
      if (node == first)
        {
          if (node->next)
            {
              first = node->next;
              node->next->prev = nullptr;
              return node->next;
            }
          else
            {
              first = last = nullptr;
              return nullptr;
            }
        }
      else if (node == last)
        {
          if (node->prev)
            {
              last = node->prev;
              node->prev->next = nullptr;
            }
          else
            {
              first = last = nullptr;
              return nullptr;
            }
        }
      else
        {
          node->next->prev = node->prev;
          node->prev->next = node->next;
          return node->next;
        }
    }

    Link *advance (Link *node, int n)
    {
      for (int i { 0 } ; i < n ; ++i)
        {
          node = node->next;
        }
      return node;
    }

    Link *first;
    Link *last;
    Link *current;
};


