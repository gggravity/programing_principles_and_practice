//
// Created by martin on 10/24/22.
//

#include "../std_lib.h"

//#include <bits/stdc++.h>
//
//using namespace std;

void failed ()
{
//  cout << terminal_colors::red ("failed") << endl;
}

struct Test
{
    string label;
    int value { };
    vector<int> sequence;
    bool result { };
};

ostream &operator<< (ostream &os, const Test &test)
{
  os << test.label << " " << test.value << " " << test.sequence << " " << test.result;
  return os;
}

istream &operator>> (istream &is, Test &test)
{
  char first;
  char last;
  double dbl;

  char first_vector;
  char last_vector;

  int i;
  vector<int> sequence;

  is >> first >> test.label >> test.value >> first_vector;

  while (is >> i)
    {
      sequence.push_back (i);
    }
  is.clear ();

  test.sequence = sequence;
  is >> last_vector >> test.result >> last;

  if (last != '}')
    {
      is.clear (ios_base::failbit);
      return is;
    }
  return is;
}

int test_all (istream &is)
{
  int error_count { 0 };
  for (Test test ; is >> test ;)
    {
      bool result { binary_search (test.sequence.begin (),
                                   test.sequence.end (),
                                   test.value) };
      if (result != test.result)
        {
          cout << terminal_colors::red ("failure: test" + test.label
                                        + " binary_search: " + to_string (test.sequence.size ())
                                        + " elements," + " val == " + to_string (test.value)
                                        + " -> " + to_string (test.result));
          cout << endl;
          error_count++;
        }
      else
        {
          cout << terminal_colors::green ("success: test" + test.label
                                          + " binary_search: " + to_string (test.sequence.size ())
                                          + " elements," + " val == " + to_string (test.value)
                                          + " -> " + to_string (test.result));
          cout << endl;
        }
    }
  return error_count;
}

int main (int argc, char *argv[])
{
  /*
  vector<int> v { 1, 2, 3, 5, 8, 12, 21 };
  if (!binary_search (v.begin (), v.end (), 1))
    {
      failed ();
    }
  if (!binary_search (v.begin (), v.end (), 5))
    {
      failed ();
    }
  if (!binary_search (v.begin (), v.end (), 8))
    {
      failed ();
    }
  if (!binary_search (v.begin (), v.end (), 21))
    {
      failed ();
    }
  if (binary_search (v.begin (), v.end (), -7))
    {
      failed ();
    }
  if (binary_search (v.begin (), v.end (), 4))
    {
      failed ();
    }
  if (binary_search (v.begin (), v.end (), 22))
    {
      failed ();
    }
  for (int test_value : { 1, 5, 8, 21, -7, 2, 44 })
    {
      if (!binary_search (v.begin (), v.end (), test_value))
        {
          failed ();
        }
    }
*/
  ifstream ifs { "../c26/tests.txt" };
  auto errors { test_all (ifs) };
  cout << "numbers of errors " << errors << endl;

  return EXIT_SUCCESS;
}
