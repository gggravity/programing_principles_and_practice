#include "../std_lib.h"
using namespace chrono;

auto get_random_double_vector (int n)
{
  random_device rd;
  mt19937 gen (rd ());
  uniform_real_distribution<> dist (1, 10);

  vector<double> vd;

  for (int i = 0 ; i < n ; i++)
    {
      vd.emplace_back (dist (gen));
    }
  return vd;
}

void vector_double_test (int n)
{

  auto test1 { get_random_double_vector (n) };

  auto t1 { system_clock::now () };

  sort (test1.begin (), test1.end ());

  auto t2 { system_clock::now () };

  auto time = duration_cast<microseconds> (t2 - t1).count ();

  cout << "time taken: " << time << " milliseconds" << endl;
}

int main (int argc, char *argv[])
{
  header ("500.000 double test");
  vector_double_test (500000);

  header ("5.000.000 double test");
  vector_double_test (5000000);

  return EXIT_SUCCESS;
}
