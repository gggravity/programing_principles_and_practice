//
// Created by martin on 16/01/2022.
//

#include <iomanip>
#include <algorithm>
#include <fstream>
#include "temp_stats.h"

ostream &operator<< (ostream &os, const Reading &reading)
  {
	os << setprecision(2) << fixed;
	os << reading.hour << " " << reading.temperature;
	return os;
  }

istream &operator>> (istream &is, Reading &reading)
  {
	is >> reading.hour >> reading.temperature;
	return is;
  }

void print_readings (vector<Reading> &readings)
  {

	for (auto r: readings)
	  {
		cout << r << endl;
	  }
  }

vector<Reading> load_readings (const string &filename)
  {
	ifstream ifs {filename};

	if (!ifs)
	  {
		cerr << "Error: can't open file: " << filename;
	  }

	vector<Reading> vr;
	int hour;
	double temp;

	while (!ifs.eof())
	  {
		ifs >> hour >> temp;
		vr.emplace_back(hour, temp);
	  }
	return vr;
  }

double get_mean (vector<Reading> &readings)
  {
	double mean {0};
	for (auto &r: readings)
	  {
		mean += r.temperature;
	  }
	mean /= double(readings.size());

	return mean;
  }

double get_median (vector<Reading> &readings)
  {
	vector<Reading> sorted = readings;
	sort(sorted.begin(), sorted.end(),
		 [] (Reading a, Reading b)
		   { return a.temperature < b.temperature; });
	double median = sorted.at(sorted.size() / 2).temperature;
	return median;
  }