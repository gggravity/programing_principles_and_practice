//
// Created by martin on 10/25/22.
//

#include "../std_lib.h"

template < typename T >
struct Test_vector : std::vector<T>
{
    using std::vector<T>::vector;    // inheriting constructor

    friend ostream &operator<< (ostream &os, const Test_vector &v)
    {
      os << "{ ";
      for (auto iter { v.begin () } ; iter != v.end () ; ++iter)
        {
          iter != v.end () - 1 ? os << *iter << ", " : os << *iter;
        }
      os << " }";
      return os;
    }

    friend istream &operator>> (istream &is, Test_vector<T> &v)
    {
      string str, first, last;

      is >> first;

      while (is >> str && str != "}")
        {
          v.push_back (boost::lexical_cast<T> (str));
        }

      is.unget ();

      is >> last;

      return is;
    }
};

template < typename T >
auto binary_search (const Test_vector<T> &v, const T &to_find)
{
  if (v.empty ())
    {
      cout << "vector is empty" << endl;
      return false;
    }

  int low { 0 };
  auto high = int (v.size () - 1);

  while (high - low > 1)
    {
      int middle = (high + low) / 2;
      if (v[middle] < to_find)
        {
          low = middle + 1;
        }
      else
        {
          high = middle;
        }
    }

  if (v[low] == to_find)
    {
      cout << "Found \"" << to_find << "\" at index " << low << endl;
      return true;
    }
  else if (v[high] == to_find)
    {
      cout << "Found \"" << to_find << "\" at index " << high << endl;
      return true;
    }
  else
    {
      cout << "\"" << to_find << "\" not found" << endl;
      return false;
    }
}

template < typename T >
struct Test
{
    T to_find { };
    Test_vector<T> sequence;
    bool result { };

    friend ostream &operator<< (ostream &os, const Test &t)
    {
      os << "{ ";

      os << t.to_find << " ";

      os << t.sequence << " ";

      os << t.result << " ";

      os << "}";

      return os;
    }

    friend istream &operator>> (istream &is, Test<T> &t)
    {
      string str, first, last;

      is >> first;

      is >> t.to_find;

      is >> t.sequence;

      is >> t.result;

      is >> last;

      return is;
    }
};

template < typename T >
auto run_tests (const string &filename)
{
  ifstream ifs { filename };

  if (!ifs.is_open ())
    {
      cerr << "Error opening file" << endl;
    }

  for (string line ; getline (ifs, line) ;)
    {
//      cout << "line: " << line << endl;
      Test<T> test;
      istringstream iss { line };
      iss >> test;
      cout << "test: " << test << endl;

      auto result { ::binary_search (test.sequence, test.to_find) };

      if (result == test.result)
        {
          cout << terminal_colors::green ("Test succeeded: ")
               << result << " == " << test.result << endl;
        }
      else
        {
          cout << terminal_colors::red ("Test failed: ")
               << result << " != " << test.result << endl;
        }
      cout << endl;
    }
}

int main (int argc, char *argv[])
{
  header ("int tests", true);
  run_tests<int> ("../c26/test_int.txt");

  header ("double tests");
  run_tests<double> ("../c26/test_double.txt");

  header ("string tests");
  run_tests<string> ("../c26/test_string.txt");

  return EXIT_SUCCESS;
}
