#include "Simple_window.h"
#include <bits/stdc++.h>
#include "Binary_tree.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
    Simple_window window { { 0, 0 }, x_max(), y_max(), "Exercise 11" };

    unique_ptr<Binary_tree> root = make_unique<Binary_tree>(1);

    root->left = make_unique<Binary_tree>(2);
    root->right = make_unique<Binary_tree>(3);
    root->left->left = make_unique<Binary_tree>(4);

    Binary_tree::print(root);

    //    window.wait_for_button();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }



