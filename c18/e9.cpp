#include <bits/stdc++.h>

using namespace std;

int static_storage = 123;

int main (int argc, char *argv[])
try
  {
    int stack_storage = 123;
    auto free_storage = new int { 123 };

    map<int *, string> memory_order = {
        { &stack_storage,  "stack_storage" },
        { &static_storage, "static_storage" },
        { free_storage,    "free_storage" }
    };

    for (auto &i : memory_order)
      {
        cout << i.first << " " << i.second << endl;
      }

    int stack_array[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    if (stack_array[0] - stack_array[9] > 0)
      {
        cout << "stack grow downward." << endl;
      }
    else
      {
        cout << "stack grow upward." << endl;
      }

    auto free_storage_array = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    if (free_storage_array[0] - free_storage_array[9] > 0)
      {
        cout << "free storage grow downward." << endl;
      }
    else
      {
        cout << "free storage grow upward." << endl;
      }

  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
