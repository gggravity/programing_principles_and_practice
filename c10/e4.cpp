//
// Created by martin on 16/01/2022.
//

#include "store_temps.h"

int main ()
  {
	vector<Reading> readings = generate_readings(100);
	write_readings(readings, "../c10/raw_temps.txt");
	print_readings(readings);
  }