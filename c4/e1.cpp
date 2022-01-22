#include "../std_lib_facilities.h"

int main ()
{

  for (char c = 'a'; c <= 'z'; c++)
  {
	constexpr int diff = 'A' - 'a';
	cout << c << '\t' << int(c) << '\t' << char(c + diff) << '\t' << int(c + diff) << endl;
  }


//  constexpr double jpy = 0.0087;
//  constexpr double eur = 1.13;
//  constexpr double gbp = 1.34;
//
//  double amount {0};
//  char code;
//
//  cout << "Enter dollar amount and currency code to convert" << endl;
//  cout << "j for yen, e for euro and, p for british pounds and q to quit:" << endl;
//
//  while (cin >> amount >> code)
//  {
//	switch (code)
//	{
//	case 'j':
//	  cout << "$" << amount << " = " << amount / jpy << " japanese yen." << endl;
//	  break;
//	case 'e':
//	  cout << "$" << amount << " = " << amount / eur << " EURO." << endl;
//	  break;
//	case 'p':
//	  cout << "$" << amount << " = " << amount / gbp << " British pounds." << endl;
//	  break;
//	default:
//	  cerr << "Wrong currency." << endl;
//	}
//	cout << "Enter dollar amount and currency code to convert" << endl;
//	cout << "j for yen, e for euro and, p for british pounds and q to quit:" << endl;
//  }


//  while (cin >> amount >> code)
//  {
//	if (code == "jpy")
//	{
//	  cout << "$" << amount << " = " << amount / jpy << " japanese yen.";
//	}
//	else if (code == "eur")
//	{
//	  cout << "$" << amount << " = " << amount / eur << " EURO.";
//	}
//	else if (code == "gbp")
//	{
//	  cout << "$" << amount << " = " << amount / gbp << " British pounds.";
//	}
//	else
//	{
//	  cerr << "Wrong currency." << endl;
//	}
//	cout << endl << "Enter dollar amount and currency code to convert:" << endl;
//  }

}