//
// Created by martin on 16/01/2022.
//

#ifndef _STORE_TEMPS_H_
#define _STORE_TEMPS_H_

#include "../std_lib_facilities.h"

enum class Unit
	{
		CELSIUS, FAHRENHEIT
	};

ostream &operator<< (ostream &os, const Unit &unit);

struct Reading
	{
		int hour {};
		double temperature {};
		Unit unit;

		Reading (int hour, double temperature, Unit unit);
	};

ostream &operator<< (ostream &os, const Reading &reading);

vector<Reading> generate_readings (int n);

double fRand (double fMin, double fMax);

void write_readings (vector<Reading> &readings, const string &filename);

void print_readings (vector<Reading> &readings);

double celsius_to_fahrenheit (double celsius);

double fahrenheit_to_celsius (double fahrenheit);

#endif //_STORE_TEMPS_H_
