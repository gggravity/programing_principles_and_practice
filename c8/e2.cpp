//
// Created by martin on 12/01/2022.
//

#include <ranges>

#include "../std_lib_facilities.h"

void print (const string &label, vector<int> &v);

void fibonacci (int x, int y, vector<int> &v, int n);

void reverse_inplace(vector<int> &v);

vector<int> reverse_with_return(vector<int> const &v);

int main ()
  {
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print("My label", v);

	vector<int> test1 {};
	vector<int> test2 {};

	fibonacci(3, 5, test1, 10);
	fibonacci(8, 13, test2, 4);

	print("test1", test1);
	print("test2", test2);

	vector<int> max_test {};
	fibonacci(8, 13, max_test, 1000);

	cout << "max int approximately " << max_test.back() << endl;

	vector<int> reversed = reverse_with_return(test2);
	reverse_inplace(test2);
	print("reversed test2:", test2);
	print("reversed:", reversed);

  }

vector<int> reverse_with_return(vector<int> const &v)
  {
	vector<int> return_vector;
	for (int it : std::ranges::reverse_view(v))
	  {
		return_vector.push_back(it);
	  }
	return return_vector;
  }

void reverse_inplace(vector<int> &v)
  {
	for (auto it_front = v.begin(), it_back = v.end() -1;
	it_front < it_back;
	++it_front, --it_back
	)
	  {
		iter_swap(it_front, it_back);
	  }
  }

void fibonacci (int x, int y, vector<int> &v, int n)
  {
	constexpr int start_length {2};
	v.push_back(x);
	v.push_back(y);

	for (int i = start_length ; i < n ; ++i)
	  {
		int fib = v[i - 1] + v[i - 2];
		if (fib > 0)
		  {
			v.push_back(fib);
		  }
		else
		  {
			cerr << "Max int reached" << endl;
			break;
		  }
	  }

  }

void print (const string &label, vector<int> &v)
  {
	cout << label << "(" << v.size() << ")" << " = " << "{ ";
	for (auto it = v.begin() ; it != v.end() ; ++it)
	  {
		if (it != v.end() - 1)
		  {
			cout << *it << ", ";
		  }
		else
		  {
			cout << *it << " }" << endl;
		  }
	  }
  }