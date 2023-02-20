#include <bits/stdc++.h>

using namespace std;


string cat_dot (const string &s1, const string &s2)
  {
    return s1 + '.' + s2;
  }

int main (int argc, char *argv[])
try
  {
    cout << cat_dot("Niels", "Bohr");
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
