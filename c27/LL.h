//
// Created by martin on 10/28/22.
//

#pragma once

struct List
{
    struct Link *first;
    struct Link *last;
};

struct Link
{
    struct Link *prev;
    struct Link *next;
};

void init (struct List *list);
struct List *crate ();
void clear (struct List *list);
void destroy (struct List *list);

void push_back (struct List *list, struct Link *new_node);
void push_front (struct List *list, struct Link *new_node);

void insert (struct List *list, struct Link *previous_node, struct Link *new_node);
struct Link *erase (struct List *list, struct Link *new_node);

struct Link *advance (struct Link *node, int n);

