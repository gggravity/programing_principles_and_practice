#include <bits/stdc++.h>

using namespace std;

void f (int array[], int n)
  {
    int la[10];

    for (int i { 0 } ; i < 10 ; ++i)
      {
        la[i] = array[i];
        cout << la[i] << " ";
      }
    cout << endl;

    auto p = new int[10];

    for (int i { 0 } ; i < 10 ; ++i)
      {
        p[i] = array[i];
        cout << p[i] << " ";
      }
    cout << endl;

    delete[] p;

  }

int ga[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

int main (int argc, char *argv[])
  {
    f(ga, 10);

    auto aa = new int[] {  1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    f(aa, 10);
  }
