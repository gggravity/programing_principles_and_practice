//
// Created by martin on 11/01/2022.
//

#include "../../std_lib_facilities.h"

void swap_w (int, int);

void swap_r (int &, int &);

void swap_cr (const int &, const int &);

int main ()
  {
	int x = 7;
	int y = 9;

	swap_w(x,y);
	swap_r(x,y);
	swap_cr(x,y);

	swap_w(7,9);
	swap_r(7,9);
	swap_cr(7,9);

	const int cx = 7;
	const int cy = 9;

	swap_w(cx,cy);
	swap_r(cx,cy);
	swap_cr(cx,cy);

	swap_w(7.7,9.9);
	swap_r(7.7,9.9);
	swap_cr(7.7,9.9);

	double dx = 7.7;
	double dy = 9.9;

	swap_w(dx,dy);
	swap_r(dx,dy);
	swap_cr(dx,dy);

	swap_w(7.7,9.9);
	swap_r(7.7,9.9);
	swap_cr(7.7,9.9);






  }

void swap_w (int a, int b)
  {
	int temp;
	temp = a;
	a = b;
	b = temp;
  }
void swap_r (int &a, int &b)
  {
	int temp;
	temp = a;
	a = b;
	b = temp;
  }
void swap_cr (const int &a, const int &b)
  {
	int temp;
	temp = a;
	a = b;
	b = temp;
  }