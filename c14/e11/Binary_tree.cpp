//
// Created by martin on 02/02/2022.
//

#include "Binary_tree.h"

Binary_tree::Binary_tree ()
  {
    root->data = counter;
    root->left = nullptr;
    root->right = nullptr;
  }

//Binary_tree::Binary_tree (int levels)
//  {
//    root->data = levels;
//    root->left = nullptr;
//    root->right = nullptr;
//  }

void Binary_tree::print (unique_ptr<Node> &node, int indent)
  {
//    static int line { 0 };
//    cout << "Line " << line << endl;
    if (node != nullptr)
      {

        printf("%02d\n", node->data);

        if (node->left)
          {
            print(node->left, indent + 8);
          }
        if (node->right)
          {
            print(node->right, indent + 8);
          }
        if (indent)
          {
            cout << setw(indent) << ' ';
          }

      }
//    line++;
  }

void Binary_tree::create_levels (unique_ptr<Node> &node, int levels, int depth)
  {
//    cout << "levels: " << levels << endl;
//    cout << "depth: " << depth << endl;
    depth++;

    if (depth > levels)
      {
        return;
      }

    node->left = make_unique<Node>(++counter);
    node->right = make_unique<Node>(++counter);

//    cout << "depth: " << depth << "     count: " << counter << endl;

    create_levels(node->left, levels, depth);
    create_levels(node->right, levels, depth);
  }

void Binary_tree::draw_lines () const
  {
    Shape::draw_lines();
  }


