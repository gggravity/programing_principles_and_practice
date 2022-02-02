//
// Created by martin on 02/02/2022.
//

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include "bits/stdc++.h"
#include "Graph.h"

using namespace std;
using namespace Graph_lib;

class Binary_tree : public Shape
      {
      public:
            Binary_tree ();

            explicit Binary_tree (int value);

            static void print (unique_ptr<Binary_tree> &btree, int indent = 0);

            int data;
            unique_ptr<Binary_tree> left { };
            unique_ptr<Binary_tree> right { };

      private:

      };



#endif //_BINARY_TREE_H_
