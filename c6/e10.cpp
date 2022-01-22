#include "../std_lib_facilities.h"

struct Input
	{
		int64_t a;
		int64_t b;
	};

istream &operator>> (istream &is, Input &input)
  {
	is >> input.a;
	is >> input.b;
	return is;
  }

int64_t factorial (int64_t n);

int64_t permutations (Input input);

int64_t combinations (Input input);

Input &get_input (Input &input);

int main ()
  {

	while (true)
	  {
		cout << "Do you want to know the permutations (p) or combinations (c) or (q) to quit?" << endl;
		string s;
		cin >> s;

		Input input {};

		switch (s.front())
		  {
			case 'p':
			  {
				input = get_input(input);
				int64_t P = permutations(input);
				cout << "P(" << input.a << "," << input.b << ") = " << P << endl;
				break;
			  }
			case 'c':
			  {
				input = get_input(input);
				int64_t C = combinations(input);
				cout << "C(" << input.a << "," << input.b << ") = " << C << endl;
				break;
			  }
			case 'q':
			  {
				exit(EXIT_SUCCESS);
			  }
			default:
			  {
				cerr << "Wrong input" << endl;
				cin.clear();
				fflush(stdin);
				break;
			  }
		  }
	  }
  }

int64_t permutations (Input input)
  {
	return factorial(input.a) / factorial((input.a - input.b));
  }

int64_t combinations (Input input)
  {
	return permutations(input) / factorial(input.b);
  }

int64_t factorial (int64_t n)
  {
	int64_t fact = 1;

	if (n == 0)
	  {
		return fact;
	  }
	else
	  {
		for (int i {1} ; i <= n ; ++i)
		  {
			fact *= i;
		  }
	  }
	return fact;
  }

Input &get_input (Input &input)
  {
	cout << "Please enter possible numbers (a):" << endl;
	cin >> input.a;
	cout << "Please enter combinations (b):" << endl;
	cin >> input.b;

	return input;
  }