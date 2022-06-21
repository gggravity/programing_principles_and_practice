#include <bits/stdc++.h>

using namespace std;


string cat_dot (const string &s1, const string &s2, const string &concat)
  {
    return s1 + concat + s2;
  }

int main (int argc, char *argv[])
try
  {
    cout << cat_dot("Niels", "Bohr", ".") << endl;
    cout << cat_dot("Niels", "Bohr", " Henrik David ") << endl;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
