//
// Created by martin on 16/01/2022.
//

//#include "../std_lib_facilities.h"
#include "temp_stats.h"

int main()
  {
	vector<Reading> readings = load_readings("../c10/raw_temps.txt");
	print_readings(readings);
	double mean = get_mean(readings);

	cout << "----------------" << endl;
	cout << "mean: " << mean << endl;

	double median = get_median(readings);
	cout << "----------------" << endl;
	cout << "median: " << median << endl;

  }