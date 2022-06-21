#include "../std_lib_facilities.h"

int main ()
{
  int pennies {0};
  int nickels {0};
  int dimes {0};
  int quarters {0};
  int half_dollars {0};
  int dollars {0};

  cout << "How many pennies do you have?\n";
  cin >> pennies;
  cout << "How many nickels do you have?\n";
  cin >> nickels;
  cout << "How many dimes do you have?\n";
  cin >> dimes;
  cout << "How many quarters do you have?\n";
  cin >> quarters;
  cout << "How many half dollars do you have?\n";
  cin >> half_dollars;
  cout << "How many dollar coins do you have?\n";
  cin >> dollars;

  if (pennies)
  {
	if (pennies == 1)
	{
	  cout << "You have " << pennies << " pennie." << endl;
	}
	else
	{
	  cout << "You have " << pennies << " pennies." << endl;
	}
  }

  if (nickels)
  {
	if (nickels == 1)
	{
	  cout << "You have " << nickels << " nickel." << endl;
	}
	else
	{
	  cout << "You have " << nickels << " nickels." << endl;
	}
  }

  if (dimes)
  {
	if (dimes == 1)
	{
	  cout << "You have " << dimes << " dime." << endl;
	}
	else
	{
	  cout << "You have " << dimes << " dimes." << endl;
	}
  }

  if (quarters)
  {
	if (quarters == 1)
	{
	  cout << "You have " << quarters << " quarter." << endl;
	}
	else
	{
	  cout << "You have " << quarters << " quarters." << endl;
	}
  }

  if (half_dollars)
  {
	if (half_dollars == 1)
	{
	  cout << "You have " << half_dollars << " half dollar." << endl;
	}
	else
	{
	  cout << "You have " << half_dollars << " half dollars." << endl;
	}
  }

  if (dollars)
  {
	if (dollars == 1)
	{
	  cout << "You have " << dollars << " dollar." << endl;
	}
	else
	{
	  cout << "You have " << dollars << " dollars." << endl;
	}
  }

  double total = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars + 100 * dollars;
  cout << "The value of all your coins is " << total << " cents ($" << total / 100 << ")." << endl;

}