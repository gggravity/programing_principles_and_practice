//
// Created by martin on 18/01/2022.
//

#include "../std_lib_facilities.h"
#include "calculator/Calculator.h"

int main()
try
  {
	Calculator calculator;
	calculator.calculate();

	return 0;
  }
catch (exception &e)
  {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';')
	  { }
	return 1;
  }
catch (...)
  {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';')
	  { }
	return 2;
  }