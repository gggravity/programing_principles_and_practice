#include "../std_lib.h"
using namespace chrono;

auto get_random (int n)
{
  random_device rd;
  mt19937 gen (rd ());
  uniform_int_distribution<> dist_char (32, 126);
  uniform_int_distribution<> dist_length (0, 100);

  map<string, int> string_int_map;

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
      string_int_map.insert ({ s, 1 });
    }

  return string_int_map;
}

void test (int n)
{

  auto t1 { system_clock::now () };

  auto test { get_random (n) };

//  sort (test.begin (), test.end ());

  auto t2 { system_clock::now () };

  auto time = duration_cast<seconds> (t2 - t1).count ();

  cout << "time taken: " << time << " seconds" << endl;

}

int main (int argc, char *argv[])
{
  header ("500.000 strings in map test");
  test (500000);

  header ("5.000.000 strings in map test");
  test (5000000);

  return EXIT_SUCCESS;
}
