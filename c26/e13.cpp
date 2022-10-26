#include "../std_lib.h"
using namespace chrono;

auto get_random_string_vector (int n)
{
  random_device rd;
  mt19937 gen (rd ());
  uniform_int_distribution<> dist_char (32, 126);
  uniform_int_distribution<> dist_length (0, 100);

  vector<string> vs;

  auto len = dist_length (gen);
  for (int i = 0 ; i < n ; i++)
    {
      string s;
      for (int j = 0 ; j < len ; ++j)
        {
          auto rnd = dist_char (gen);
          auto c = (char)rnd;
          s.push_back (c);
        }
      vs.emplace_back (s);
    }

  return vs;
}

void vector_string_test (int n)
{

  auto test { get_random_string_vector (n) };

  auto t1 { system_clock::now () };

  sort (test.begin (), test.end ());

  auto t2 { system_clock::now () };

  auto time = duration_cast<seconds> (t2 - t1).count ();

  cout << "time taken: " << time << " seconds" << endl;

}

int main (int argc, char *argv[])
{
  header ("500.000 strings test");
  vector_string_test (500000);

  header ("5.000.000 strings test");
  vector_string_test (5000000);

  return EXIT_SUCCESS;
}
