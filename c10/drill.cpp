//
// Created by martin on 16/01/2022.
//

#include "../std_lib_facilities.h"
#include "Point.h"

int main ()
  {
	string input_name {"../c10/points.txt"};
	string output_name {"../c10/points_output.txt"};

	ifstream ifs {input_name};
	if (!ifs)
	  {
		error("can't open input file ", input_name);
	  }

	vector<Point> points;
	for (Point p ; ifs >> p ;)
	  {
		points.push_back(p);
	  }

	for (auto p: points)
	  {
		cout << p << endl;
	  }

	ofstream ofs {output_name};
	if (!ofs)
	  {
		error("can't open output file ", output_name);
	  }

	for (Point p : points)
	  {
		ofs << p << endl;
	  }

	ifs.close();
	ofs.close();
  }