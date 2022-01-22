//
// Created by martin on 15/01/2022.
//

#include <iostream>

#include "Rational.h"

using namespace std;

int main ()
  {
	Rational r1 {1, 2};
	Rational r2 {1, 2};
	Rational r3 {1, 3};

	cout << (r1 == r2) << endl;
	cout << (r1 == r3) << endl;
	cout << (r1 != r3) << endl;

	cout << "------------------------------------------------" << endl;
	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;

	cout << "------------------------------------------------" << endl;
	cout << "r1 < r2: " << (r1 < r2) << endl;
	cout << "r1 < r3: " << (r1 < r3) << endl;
	cout << "r1 > r3: " << (r1 > r3) << endl;
	cout << "r1 => r2: " << (r1 >= r2) << endl;

	cout << "------------------------------------------------" << endl;
	cout << "r1 + r2: " << (r1 + r2) << endl;
	cout << "r1 + r3: " << (r1 + r3) << endl;
	cout << "r1 - r3: " << (r1 - r3) << endl;
	cout << "r1 * r3: " << (r1 * r3) << endl;
	cout << "r1 / r3: " << (r1 / r3) << endl;

	cout << "------------------------------------------------" << endl;
	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;
	cout << "------------------------------------------------" << endl;
	cout << "r1 = r3" << endl;
	r1 = r3;
	cout << "r1: " << r1 << endl;
	cout << "r3: " << r3 << endl;



  }