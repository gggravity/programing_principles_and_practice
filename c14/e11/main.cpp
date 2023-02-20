//#include "Simple_window.h"
#include <bits/stdc++.h>
#include "Binary_tree.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
//    Simple_window window { { 0, 0 }, x_max(), y_max(), "Exercise 11" };

//    unique_ptr<Binary_tree> root = make_unique<Binary_tree>(1);
//
//    root->left = make_unique<Binary_tree>(2);
//    root->right = make_unique<Binary_tree>(3);
//    root->left->left = make_unique<Binary_tree>(4);

    Binary_tree btree;
//    root->left = make_unique<Node>(2);
//    root->right = make_unique<Node>(3);
//    root->left->left = make_unique<Node>(4);
//    root->left->left->left = make_unique<Node>(5);
//    root->left->left->left->left = make_unique<Node>(6);
    btree.create_levels(btree.root, 2);

//    cout << btree.root->data << endl;
//    cout << btree.root->left->data << " " << btree.root->right->data << endl;
//    cout << btree.root->left->data << " " << btree.root->right->data << endl;
//
//
//    cout << btree.root->right->right->right->right->data << endl;

//    cout << btree.counter << endl;

    Binary_tree::print(btree.root);

    //    window.wait_for_button();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
