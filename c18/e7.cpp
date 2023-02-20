#include <bits/stdc++.h>

using namespace std;

char *cat_dot (const char *s1, const char *s2, const char *concat)
  {
    struct
        {
            int s1 { 0 };
            int s2 { 0 };
            int concat { 0 };
        } counter;

    auto p_s1 = s1;
    auto p_s2 = s2;
    auto p_concat = concat;

    while (*p_s1 != '\0')
      {
        counter.s1++;
        p_s1++;
      }

    while (*p_s2 != '\0')
      {
        counter.s2++;
        p_s2++;
      }

    while (*p_concat != '\0')
      {
        counter.concat++;
        p_concat++;
      }

    auto return_string = new char[counter.s1 + counter.s2 + counter.concat + 1];
    auto p_rs = return_string;

    p_s1 -= counter.s1;
    p_s2 -= counter.s2;
    p_concat -= counter.concat;

    while (*p_s1 != '\0')
      {
        *p_rs = *p_s1;
        p_rs++;
        p_s1++;
      }

    while (*p_concat != '\0')
      {
        *p_rs = *p_concat;
        p_rs++;
        p_concat++;
      }

    while (*p_s2 != '\0')
      {
        *p_rs = *p_s2;
        p_rs++;
        p_s2++;
      }

    return return_string;
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
