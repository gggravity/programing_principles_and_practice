//
// Created by martin on 02/02/2022.
//

#include "Binary_tree.h"

Binary_tree::Binary_tree () : data { 0 },
                              left { nullptr },
                              right { nullptr }
  {
  }

Binary_tree::Binary_tree (int value) : data { value },
                                       left { nullptr },
                                       right { nullptr }
  {
  }

void Binary_tree::print (unique_ptr<Binary_tree> &btree, int indent)
  {
    if (btree != nullptr)
      {
        if (btree->left)
          {
            print(btree->left, indent + 4);
          }
        if (btree->right)
          {
            print(btree->right, indent + 4);
          }
        if (indent)
          {
            cout << setw(indent) << ' ';
          }
        cout << btree->data << "\n ";
      }
  }


