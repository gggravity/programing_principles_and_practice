//
// Created by martin on 10/26/22.
//

#include "../std_lib.h"

struct Name_age
{
    string name;
    int age { };

    friend ostream &operator<< (ostream &os, const Name_age &name_age)
    {
      os << "( ";

      os << name_age.name << " ";

      os << name_age.age << " ";

      os << ")";

      return os;
    }

    friend istream &operator>> (istream &is, Name_age &name_age)
    {
      string str, first, last;

      is >> first;

      is >> name_age.name;

      is >> str;

      is >> name_age.age;

      is >> last;

      return is;
    }
};

bool compare (const Name_age &left, const Name_age &right)
{
  if (left.name < right.name)
    {
      return true;
    }
  if (right.name < left.name)
    {
      return false;
    }
  return left.age < right.age;
}

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
      string first, last, test, to_insert, test2;

      is >> first;

      while (is >> test && test != "}")
        {
          if (test == ")")
            {
              to_insert.append (") ");
            }
          else
            {
              to_insert.append (test);
            }
        }

      istringstream iss { to_insert };
      for (string s ; getline (iss, s, ' ') ;)
        {
          T t;
          s.insert (1, " ");
          s.insert (s.size () - 1, " ");

          size_t start_pos = s.find (',');
          if (start_pos != std::string::npos)
            {
              s.replace (start_pos, 1, " , ");
            }

          istringstream iss_s { s };
          iss_s >> t;
          v.push_back (t);
        }

      is.clear ();

      return is;
    }
};

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
      string str, first, last, ch;

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
      Test<T> test;
      istringstream iss { line };

      iss >> test;
      cout << "test: " << test << endl;
      cout << "to_find: " << test.to_find << endl;
      cout << "seq: " << test.sequence << endl;
      cout << "res: " << test.result << endl;

      auto result { std::binary_search (test.sequence.begin (),
                                        test.sequence.end (),
                                        test.to_find,
                                        compare) };

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
  header ("Name age tests", true);
  run_tests<Name_age> ("../c26/test_name_age.txt");

  return EXIT_SUCCESS;
}
