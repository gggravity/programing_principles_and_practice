//
// Created by martin on 15/01/2022.
//

#include <iostream>

#include "Money.h"

using namespace std;

int main ()
  {
	Money m1 {100, Currency::USD};
	Money m2 {100, Currency::DKK};
	Money m3 {200, Currency::DKK};
	cout << m1 << endl;
	cout << m1 + 100 << endl;
	cout << m2 + m3 << endl;

	cout << m2 - m3 << endl;

//	cout << m1 + m3 << endl;

	Money m4;
	cin >> m4;
	cout << m4;
  }
