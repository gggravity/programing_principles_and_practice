//
// Created by martin on 20/01/2022.
//

#include "Simple_window.h"
#include "Graph.h"

using namespace std;
using namespace Graph_lib;

int sgn (double d)
  {
	if (d < 0)
	  {
		return -1;
	  }
	else if (d > 0)
	  {
		return 1;
	  }
	return 0;
  }

vector<Point> super_ellipse (double a, double b, double m, double n)
  {
	int xCenter = x_max() / 2;
	int yCenter = y_max() / 2;
	double precision = 0.01;

	vector<Point> points;
	Point temp;
	Point point;

	for (double d = -1.0 ; d < 1.0 ;)
	  {
		double t = d * std::numbers::pi;
		int x = int(a * pow(abs(cos(t)), 2.0 / m) * sgn(cos(t)));
		int y = int(b * pow(abs(sin(t)), 2.0 / n) * sgn(sin(t)));

		point = Point {x + xCenter, y + yCenter};
		if (temp != point)  // Check for duplicates
		  {
			points.push_back(point);
		  }
		temp = point;
		d += precision;
	  }
	return points;
  }

int main ()
try
  {
	Simple_window win(Point {0, 0}, x_max(), y_max(), "Super-ellipse");

	Graph_lib::Open_polyline op;

	vector<Point> points = super_ellipse(300, 300, 0.5, 2.5);

	for (Point p : points)
	  {
		op.add(p);
	  }

	win.attach(op);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }