//
// Created by martin on 10/28/22.
//

#pragma once

typedef struct Link
{
    struct Link *prev;
    struct Link *next;
} Link;

typedef struct
{
    Link *first;
    Link *last;
} List;



void init (List *list);
List *crate ();
void clear (List *list);
void destroy (List *list);

void push_back (List *list, Link *new_node);
void push_front (List *list, Link *new_node);

void insert (List *list, Link *previous_node, Link *new_node);
Link *erase (List *list, Link *new_node);

Link *advance (Link *node, int n);

