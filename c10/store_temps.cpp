//
// Created by martin on 16/01/2022.
//

#include "store_temps.h"

Reading::Reading (int hour, double temperature, Unit unit) :
	hour {hour},
	temperature {temperature},
	unit {unit}
  {
	if (hour < 0 || hour > 23)
	  {
		error("Error: hour out of range");
	  }
	if (unit != Unit::CELSIUS && unit != Unit::FAHRENHEIT)
	  {
		error("Error: wrong temperature unit");
	  }
	if (unit == Unit::FAHRENHEIT)
	  {
		this->temperature = fahrenheit_to_celsius(temperature);
		this->unit = Unit::CELSIUS;
	  }
  }

ostream &operator<< (ostream &os, const Unit &unit)
  {
	switch (unit)
	  {
		case Unit::CELSIUS:
		  os << "C";
		break;
		case Unit::FAHRENHEIT:
		  os << "F";
		break;
	  }
	return os;
  }

void write_readings (vector<Reading> &readings, const string &filename)
  {
	ofstream ofs {filename};

	for (auto r: readings)
	  {
		ofs << r << endl;
	  }
  }

void print_readings (vector<Reading> &readings)
  {

	for (auto r: readings)
	  {
		cout << r << endl;
	  }
  }

vector<Reading> generate_readings (int n)
  {
	vector<Reading> readings;

	for (int i {0} ; i <= n ; ++i)
	  {

		Unit unit {Unit::FAHRENHEIT};
		Reading r {randint(0, 23), fRand(30.0, 100.0), unit};
		readings.push_back(r);
	  }
	return readings;
  }

double fRand (double fMin, double fMax)
  {
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
  }

ostream &operator<< (ostream &os, const Reading &reading)
  {
	os << setprecision(2) << fixed;
	os << reading.hour << " " << reading.temperature << " " << reading.unit;
	return os;
  }

double celsius_to_fahrenheit (double celsius)
  {
	// (F − 32) × 5/9 = C
	return celsius * 9 / 5 + 32;
  }

double fahrenheit_to_celsius (double fahrenheit)
  {
	return (fahrenheit - 32) * 5 / 9;
  }
