//
// Created by martin on 10/24/22.
//

#include "../std_lib.h"

template < typename T >
struct Test
{
    string label { "default" };
    T value;
    vector<T> sequence;
    bool result { };
};

void failed ()
{
  cout << terminal_colors::red ("failed") << endl;
}

template < typename T >
void print_test_result (const Test<T> &test, bool failure)
{
  string test_string;

  if (failure)
    {
      test_string.append (terminal_colors::red ("failure: "));
    }
  else
    {
      test_string.append (terminal_colors::green ("success: "));
    }

  test_string.append ("binary_search: " + to_string (test.sequence.size ())
                      + " elements," + " val == " + test.value
                      + " -> " + to_string (test.result));

  cout << test_string << endl;
}

auto make_test (const string &lab, int n, int base, int spread)
{
  stringstream ss;
  int elem = base;
  int val { base + randint (elem - base) };

  ss << "{ " << lab << " " << val << " { ";

  vector<int> v;

  for (int i { 0 } ; i < n ; ++i)
    {
      elem += randint (spread);
      v.push_back (elem);
    }

  bool found = false;
  for (int i { 0 } ; i < n ; ++i)
    {
      if (v[i] == val)
        {
          found = true;
        }
      ss << v[i] << " ";
    }
  ss << "} " << found << " }" << endl;
  return ss;
}

template < typename T >
ostream &operator<< (ostream &os, const Test<T> &test)
{
  os << test.label << " " << test.value << " " << test.sequence << " " << test.result;
  return os;
}

template < typename T >
istream &operator>> (istream &is, Test<T> &test)
{
  char first;
  char last;

  char first_vector;
  char last_vector;

  T i;
  vector<T> sequence;

  is >> first >> test.label >> test.value >> first_vector;

  while (is >> i && i != "}")
    {
      sequence.push_back (i);
    }
  is.unget ();
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

template < typename T >
int test_all (istream &is)
{
  int error_count { 0 };
  for (Test<T> test ; is >> test ;)
    {
      bool result { binary_search (test.sequence.begin (),
                                   test.sequence.end (),
                                   test.value) };
      if (result != test.result)
        {
          print_test_result (test, true);
          error_count++;
        }
      else
        {
          print_test_result (test, false);
        }
    }
  return error_count;
}

auto make_random_string_test ()
{
  vector<string> vs { "Bohr", "Darwin", "Einstein", "Levoisier", "Newton", "Turing", "Willis", "Robbins", "Sylvester",
                      "Jennings", "Gerald", "Lawson", "Guy", "Miranda", "Raymond", "Johnston", "Chad", "Greer", "Jesus",
                      "Hutchinson", "Omar", "Albert", "Keith", "James", "Fernando", "Williams", "Sam", "Dyer", "Nick",
                      "Whitaker", "Roosevelt", "Washington", "Mark", "Whitley", "Tracy", "Riddle", "Randolph",
                      "McLaughlin", "Dennis", "Perry", "Rodney", "Foley", "Luke", "Jarvis", "Landon", "Ewing" };

  auto seed = chrono::system_clock::now ().time_since_epoch ().count ();
  default_random_engine engine (seed);
  shuffle (vs.begin (), vs.end (), engine);

  vector<string> val;
  sample (vs.begin (), vs.end (), back_inserter (val), 1, engine);

  auto to_pop { randint (2 * int (vs.size ()) / 3) };
  for (auto i { 0 } ; i < to_pop ; ++i)
    {
      vs.pop_back ();
    }

  sort (vs);
  stringstream ss;

  ss << "{ " << "lab" << " " << val.front () << " { ";

  bool found = false;
  for (const auto &person : vs)
    {
      if (person == val.front ())
        {
          found = true;
        }
      ss << person << " ";
    }
  ss << "} " << found << " }" << endl;
  return ss;

}
int main (int argc, char *argv[])
{
/*  vector<int> v { 1, 2, 3, 5, 8, 12, 21 };
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
  ifstream ifs { "../c26/tests.txt" };
  auto errors { test_all (ifs) };
  cout << "numbers of errors " << errors << endl;*/
/*

  int no_of_tests { 10000 };
  auto errors { 0 };

  for (int i { 0 } ; i < no_of_tests ; ++i)
    {
      string lab { "rand_test_" };
      auto stream = make_test (lab + to_string (i),
                               randint (500),
                               0,
                               randint (50));
      auto error = test_all (stream);
      errors += error;
    }


  cout << "numbers of errors " << errors << endl;
  cout << "numbers of tests " << no_of_tests << endl;
*/
/*
  int no_of_tests { 10 };
  auto errors { 0 };

  for (int i { 0 } ; i < no_of_tests ; ++i)
    {
      string lab { "rand_test_" };
      auto stream = make_test (lab + to_string (i),
                               i,
                               0,
                               10);
      auto error = test_all (stream);
      errors += error;
      cout << stream.str () << endl;
    }
    */

  int no_of_tests { 100 };
  auto errors { 0 };

  for (int i { 0 } ; i < no_of_tests ; ++i)
    {
      string lab { "rand_test_" };
      auto stream = make_random_string_test ();
      auto error = test_all<string> (stream);
      errors += error;
    }

  cout << "numbers of errors " << errors << endl;
  cout << "numbers of tests " << no_of_tests << endl;

  return EXIT_SUCCESS;
}

