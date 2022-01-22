#include "../std_lib_facilities.h"

int main ()
{
  vector<int> check_points = {1000, 1'000'000, 1'000'000'000};
  vector<int> squares_count;

  int grains {3};
  int squares {2};

  while (grains <= check_points.back())
  {
	if (grains >= check_points[0] && squares_count.empty())
	{
	  squares_count.push_back(squares);
	}
	if (grains >= check_points[1] && squares_count.size() == 1)
	{
	  squares_count.push_back(squares);
	}

	grains *= grains;
	++squares;
  }
  squares_count.push_back(squares);

  for (int i {0} ; i != check_points.size() ; ++i)
  {
	cout << squares_count[i] << " squares are required for " << check_points[i] << " grains." << endl;
  }
}