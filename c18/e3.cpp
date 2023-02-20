#include <bits/stdc++.h>

using namespace std;

int str_cmp (const char *s1, const char *s2)
  {
    auto p1 = s1;
    auto p2 = s2;

    while (*p1 != '\0' && *p1 == *p2)
      {
        // skip to first neq char or \0
        p1++;
        p2++;
      }

    return *p1 - *p2;
  }

int main (int argc, char *argv[])
try
  {
    cout << str_cmp("Aaaadam", "Aaadam") << endl;
    cout << str_cmp("Adam", "Eva") << endl;
    cout << str_cmp("Eva", "Adam") << endl;
    cout << str_cmp("Eva", "Eva") << endl;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
