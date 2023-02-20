//
// Created by martin on 02/02/2022.
//

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;
using namespace Graph_lib;

struct Node
    {
        int data;
        unique_ptr<Node> left = nullptr;
        unique_ptr<Node> right = nullptr;

        explicit Node (int data) : data(data)
          { }
    };

struct Binary_tree : Shape
      {
            Binary_tree ();

//            explicit Binary_tree (int levels);

            void create_levels (unique_ptr<Node> &node, int levels, int depth = 0);

            static void print (unique_ptr<Node> &node, int indent = 0);

            unique_ptr<struct Node> root = make_unique<Node>(counter);

            int counter = 1;

      protected:
            virtual void draw_lines () const override;

      private:

      };



#endif //_BINARY_TREE_H_
