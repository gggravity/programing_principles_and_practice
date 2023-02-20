#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
  {
    int stack_allocating_a = 123;
    int stack_allocating_b = 123;

    auto ptr_a = &stack_allocating_a;
    auto ptr_b = &stack_allocating_b;

    if (ptr_a < ptr_b)
      {
        cout << "The stack grow toward higher addresses." << endl;
      }
    else
      {
        cout << "The stack grow toward lower addresses." << endl;
      }

    auto heap_allocating_a = new int { 123 };
    auto heap_allocating_b = new int { 123 };

    ptr_a = heap_allocating_a;
    ptr_b = heap_allocating_b;

    if (ptr_a < ptr_b)
      {
        cout << "The heap grow toward higher addresses." << endl;
      }
    else
      {
        cout << "The heap grow toward lower addresses." << endl;
      }

  }
