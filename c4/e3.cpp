#include <cfloat>
#include "../std_lib_facilities.h"

int main ()
{
  vector<double> distances;

  cout << "Enter distance between cities along a route: " << endl;
  for (double distance ; cin >> distance ;)
  {
	distances.push_back(distance);
  }

  double total_distance {0};
  auto shortest = DBL_MAX;
  auto longest = DBL_MIN;

  for (auto distance: distances)
  {
	total_distance += distance;

	if (distance >= longest)
	{
	  longest = distance;
	}
	else if (distance <= shortest)
	{
	  shortest = distance;
	}
  }

  cout << "Total distance: " << total_distance << endl;
  cout << "Shortest distance: " << shortest << endl;
  cout << "Longest distance: " << longest << endl;
  cout << "Average distance: " << total_distance / double(distances.size());

}