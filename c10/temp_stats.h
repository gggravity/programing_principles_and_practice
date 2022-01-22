//
// Created by martin on 16/01/2022.
//

#ifndef _TEMP_STATS_H_
#define _TEMP_STATS_H_

//#include "../std_lib_facilities.h"

#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

class Reading
	  {
		public:
			int hour;
			double temperature;
			Reading (int hour, double temperature) : hour(hour),
													 temperature(temperature)
			  {
				if (hour < 0 || hour > 23)
				  {
					cerr << "Error: hour out of range";
				  }

			  }

	  };

vector<Reading> load_readings (const string &filename);

double get_mean (vector<Reading> &readings);

double get_median (vector<Reading> &readings);

void print_readings (vector<Reading> &readings);

ostream &operator<< (ostream &os, const Reading &reading);

istream &operator>> (istream &is, Reading &reading);

#endif //_TEMP_STATS_H_
