#include <bits/stdc++.h>

using namespace std;

void to_lower (char *s)
  {
    while (*s != '\0')
      {
        if (*s >= 'A' && *s <= 'Z')
          {
            *s = char(*s + 'a' - 'A');
          }
        s++;
      }
  }

char *str_dup (const char *ch)
  {
    auto pch = ch;
    int len = 0;

    while (*pch != '\0')
      {
        len++;
        pch++;
      }

    auto copy = new char[len];

    for (int i { 0 } ; i < len ; ++i)
      {
        copy[i] = ch[i];
      }

    return copy;
  }

char *find_x (const char *s, const char *x)
  {
    auto ptr_x = x;
    int len_x { 0 };

    while (*ptr_x != '\0')
      {
        len_x++;
        ptr_x++;
      }

    int num_found = 0;

    while (*s != '\0')
      {
        if (*s == *x)
          {
            for (int i { 0 } ; i < len_x ; ++i)
              {
                if (s[i] != x[i])
                  {
                    num_found = 0;
                    break;
                  }
                else
                  {
                    num_found++;
                  }
              }
            if (num_found == len_x)
              {
                auto found = new char[len_x];
                for (int i { 0 } ; i < len_x ; ++i)
                  {
                    found[i] = s[i];
                  }
                return found;
              }
          }
        s++;
      }
  }

int main (int argc, char *argv[])
  {
    auto pi = new int(1);
    auto pf = new float(1);
    auto pd = new double(1);
    auto pb = new bool(true);

    cout << "pi: " << pi << endl;
    cout << "pf: " << pf << endl;
    cout << "pd: " << pd << endl;
    cout << "pb: " << pb << endl;

    auto pia = new int[2];
    auto pfa = new float[2];
    auto pda = new double[2];
    auto pba = new bool[2];

    cout << "int: " << (long)&pia[1] - (long)&pia[0] << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;

    cout << "float: " << (long)&pfa[1] - (long)&pfa[0] << endl;
    cout << "sizeof(float): " << sizeof(float) << endl;

    cout << "double: " << (long)&pda[1] - (long)&pda[0] << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;

    cout << "bool: " << (long)&pba[1] - (long)&pba[0] << endl;
    cout << "sizeof(bool): " << sizeof(bool) << endl;

    char str[] = "Hello, World!";
    to_lower(str);
    cout << str << endl;

    cout << str_dup(str) << endl;

    cout << find_x("Hello worllld", "lll") << endl;

  }