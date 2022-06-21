//
// Created by martin on 13/01/2022.
//

//#include "../std_lib_facilities.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct vector_values
	{
		double smallest = numeric_limits<double>::max();
		double largest = numeric_limits<double>::min();
		double mean = 0;
		double median = 0;
	};

vector<double> calc_index (vector<double> &price, vector<double> &weight)
  {
	if (price.size() != weight.size())
	  {
		cerr << "Vectors on of the same size";
		exit(EXIT_FAILURE);
	  }
	vector<double> index;

	for (int i {0} ; i < price.size() ; ++i)
	  {
		index.push_back(price[i] * weight[i]);
	  }
	return index;
  }

double max_v (vector<double> const &v)
  {
	double largest = numeric_limits<double>::min();

	for (
	  auto d
		: v)
	  {
		if (d > largest)
		  {
			largest = d;
		  }
	  }
	return
		largest;
  }

void print (vector<double> &price, vector<double> &weight, vector<double> &index)
  {
	for (int i {0} ; i < price.size() ; ++i)
	  {
		cout << "index of (" << price[i] << ", " << weight[i] << ") = " << index[i] << endl;
	  }
  }

struct vector_values calc_vector_values (vector<double> const &v)
  {
	if (v.empty())
	  {
		exit(EXIT_FAILURE);
	  }

	vector_values vv;

	for (auto d: v)
	  {
		if (d > vv.largest)
		  {
			vv.largest = d;
		  }
		if (d < vv.smallest)
		  {
			vv.smallest = d;
		  }
		vv.mean += d;

	  }
	vv.mean /= static_cast<int>(v.size());

	vector<double> sorted(v);

	sort(sorted.begin(), sorted.end());

	vv.median = sorted[sorted.size() / 2];

	return vv;
  }

int main ()
  {
	vector<double> price {123, 321, 543, 231, 233, 123, 532};
	vector<double> weight {1.3, 1.9, 4.4, 2.2, 2.7, 0.4, 3.2};

	vector<double> index = calc_index(price, weight);
	print(price, weight, index);

	cout << "---------------------" << endl;
	cout << "max_v: " << max_v(index) << endl;

	cout << "---------------------" << endl;
	vector_values vv = calc_vector_values(index);
	cout << "smallest: " << vv.smallest << endl;
	cout << "largest: " << vv.largest << endl;
	cout << "mean: " << vv.mean << endl;
	cout << "median: " << vv.median << endl;
  }