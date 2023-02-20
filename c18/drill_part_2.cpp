#include <bits/stdc++.h>

using namespace std;

void f (vector<int> vec)
  {
    vector<int> vl(vec.size());

    copy(vec.begin(), vec.end(), vl.begin());

    for (auto &v : vl)
      {
        cout << v << " ";
      }

    cout << endl;

    vector<int> vl2 = vec;

    for (auto &v : vl)
      {
        cout << v << " ";
      }

    cout << endl;

  }

vector<int> gv { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

int main (int argc, char *argv[])
  {
    f(gv);

    vector<int> vv {  1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    f(vv);
  }
