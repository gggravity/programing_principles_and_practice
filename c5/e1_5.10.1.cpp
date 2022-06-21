#include "../std_lib_facilities.h"

int area (int length, int width)
{
  if (length <= 0 || width <= 0)
  {
	error("area() pre-condition.");
  }
  int a = length * width;
  if (a <= 0)
  {
	error("area() post-condition.");
  }
  return a;
}

int main ()
{
  area(INT_MAX, 10);
}