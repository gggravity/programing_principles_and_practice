#include <bits/stdc++.h>

using namespace std;

char *find_x (const char *s, const char *x)
{
  auto pnt_len = x;
  int counter {0};

  while (*pnt_len != '\0')
    {
      counter++;
      pnt_len++;
    }

  auto pnt_s = s;
  auto pnt_x = x;

  while (*pnt_s != '\0')
    {
      if (*pnt_s == *pnt_x)
        {
          for (int i {0}; i < counter; ++i)
            {
              if (*(pnt_s + i) != *(pnt_x + i))
                {
                  break;
                }
              else
                {
                  if (i + 1 == counter)  // remember \0 (+1)
                    {
                      return const_cast<char *> (x);
                    }
                }
            }
        }
      pnt_s++;
    }
  return nullptr;
}

int main (int argc, char *argv[])
try
  {
    char c_string[] = "Der var en gganggg en mand.";
    char to_find[] = "ggg";

    auto found_it = find_x (c_string, to_find);
    cout << found_it << endl;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
