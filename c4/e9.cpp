#include "../std_lib_facilities.h"

int main ()
{
  unsigned long long grains {3};
  int squares {2};

  cout << "squares: 1 | grains:  1" << endl;

  while (grains <= LONG_LONG_MAX)
  {
	cout << "squares: " << squares;
	cout << " | grains:  " << grains << endl;
	grains *= grains;
	++squares;
  }

}