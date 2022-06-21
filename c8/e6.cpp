//
// Created by martin on 12/01/2022.
//

#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void print (vector<string> const &v)
  {
	for (auto &n: v)
	  {
		cout << n << " ";
	  }
	cout << endl;
  }

void print (vector<int> const &v)
  {
	for (auto &n: v)
	  {
		cout << n << " ";
	  }
	cout << endl;
  }

void reverse (vector<string> &v)
  {
//	for (auto it_front = v.begin(), it_back = v.end() - 1 ;
//		 it_front < it_back ;
//		 ++it_front, --it_back)
//	  {
//		iter_swap(it_front, it_back);
//	  }

	reverse(v.begin(), v.end());
  }

vector<string> reverse_return (vector<string> const &v)
  {
	vector<string> sv;
	sv.reserve(v.size());
	for (auto it = v.crbegin() ; it != v.crend() ; ++it)
	  {
		sv.push_back(*it);
	  }
	return sv;
  }

int main ()
  {
	vector<string> names {"James", "Poul", "Brian", "Adam", "Peter"};
	vector<string> names_sorted(names);
	vector<int> ages {43, 57, 38, 29, 15};
	vector<int> ages_sorted;

	sort(names_sorted.begin(), names_sorted.end());

	cout << "--- names ---" << endl;
	for (int i {0} ; i < names.size() ; ++i)
	  {
		cout << "(" << names[i] << ", " << ages[i] << ")" << endl;
	  }

	cout << "--- names_sorted ---" << endl;
	for (int i {0} ; i < names_sorted.size() ; ++i)
	  {
		cout << "(" << names_sorted[i] << ", " << ages[i] << ")" << endl;
	  }

	cout << "--- Find index ---" << endl;

	for (const auto &n: names_sorted)
	  {
		for (int i {0} ; i < names.size() ; ++i)
		  {
			if (names[i] == n)
			  {
				ages_sorted.push_back(ages[i]);
				cout << "Found: " << names[i] << " @ " << i << endl;
			  }
		  }
	  }

	cout << "--- all sorted ---" << endl;

	for (int i {0} ; i < names_sorted.size() ; ++i)
	  {
		cout << "(" << names_sorted[i] << ", " << ages_sorted[i] << ")" << endl;
	  }

	cout << "--- trying with a map ---" << endl;

	map<string, int> name_age_map;

	for (int i {0} ; i < names.size() ; ++i)
	  {
		cout << "inserting: " << names[i] << ", " << ages[i] << endl;
		name_age_map[names[i]] = ages[i];
	  }
	for (auto &m: name_age_map)
	  {
		cout << m.first << ", " << m.second << endl;
	  }

  }