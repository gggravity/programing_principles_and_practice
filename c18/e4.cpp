#include <bits/stdc++.h>

using namespace std;

char *strdup (const char *input_string)
{
  auto pnt_counter = input_string;
  auto pnt_input = input_string;
  int counter {0};

  while (*pnt_counter != '\0')
    {
      counter++;
      pnt_counter++;
    }
  auto output_string = new char[counter + 1];  // need space for \0
  auto pnt_output = output_string;

  while (*pnt_input != '\0')
    {
      *pnt_output = *pnt_input;
      pnt_input++;
      pnt_output++;
    }

  return output_string;
}

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
    cout << "--- Part 1 --- " << endl;
    char c_string_p1[] = "Der var en gang en mand.";
    c_string_p1[24] = 'X';

    auto new_string = strdup (c_string_p1);
    cout << new_string << endl;

    cout << "--- Part 2 --- " << endl;
    char c_string_p2[] = "Der var en gganggg en mand.";
    char to_find[] = "ggg";
    c_string_p2[27] = 'X';
    to_find[3] = 'X';

    auto found_it = find_x (c_string_p2, to_find);
    cout << found_it << endl;  // it crashes here to_find is not a \0 terminated string.

    char adam[] = {'A', 'd', 'a', 'm'};
    char eva[] = {'E', 'v', 'a'};
    char aaaadam[] = {'A', 'a', 'a', 'a', 'd', 'a', 'm'};
    char aaadam[] = {'A', 'a', 'a', 'd', 'a', 'm'};
    cout << "--- Part 3 --- " << endl;
    cout << str_cmp (aaaadam, aaadam) << endl;
    cout << str_cmp (adam, eva) << endl;
    cout << str_cmp (eva, adam) << endl;
    cout << str_cmp (eva, eva) << endl;  // could give wrong answer here.
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
