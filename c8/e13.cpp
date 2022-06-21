//
// Created by martin on 13/01/2022.
//

#include "../std_lib_facilities.h"

vector<int> string_length (vector<string> const &v)
  {
	vector<int> length;

	for (auto &s: v)
	  {
		length.push_back(static_cast<int>(s.size()));
	  }
	return length;
  }

string lexicographically_first (vector<string> const &v)
  {
	auto sorted(v);
	sort(sorted.begin(), sorted.end());
	return sorted.front();
  }

string lexicographically_last (vector<string> const &v)
  {
	auto sorted(v);
	sort(sorted.begin(), sorted.end());
	return sorted.back();
  }

string find_longest (vector<string> const &v)
  {
	auto sl = string_length(v);
	auto max = max_element(sl.begin(), sl.end());
	auto index = distance(sl.begin(), max);
	return v.at(index);
  }

string find_shortest (vector<string> const &v)
  {
	auto sl = string_length(v);
	auto min = min_element(sl.begin(), sl.end());
	auto index = distance(sl.begin(), min);
	return v.at(index);
  }

int main ()
  {

	vector<string> sv {"Peter", "Poul", "Bo", "James", "Zoom", "Bike", "James", "Bo", "Tv", "Top"};

	vector<int> l = string_length(sv);

	cout << "Length of strings: ";

	for (auto i: l)
	  {
		cout << i << " ";
	  }

	cout << "-------------------" << endl;
	cout << "lexicographically_first: " << lexicographically_first(sv) << endl;
	cout << "lexicographically_last: " << lexicographically_last(sv) << endl;

	cout << "-------------------" << endl;
	cout << "shortest string: " << find_shortest(sv) << endl;
	cout << "Longest string: " << find_longest(sv) << endl;

  }