#include "../std_lib_facilities.h"

int main()
{
  cout << "Enter digits to compose into integers:" << endl;
  string input_line;
  getline(cin, input_line);

  for (auto c : input_line)
  {
	int composed = c - '0';
	if (composed >= 0 && composed <= 9)
	  cout << composed << " ";
	else
	  cout << "NaN" << " ";
  }

}

