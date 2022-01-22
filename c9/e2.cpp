//
// Created by martin on 14/01/2022.
//

#include "../std_lib_facilities.h"

class Name_pair
	  {
		public:
			void read_names ();

			void read_ages ();

//			void print ();

			void sort_pairs ();

			[[nodiscard]] vector<string> get_names () const;

			[[nodiscard]] vector<double> get_ages () const;

		private:
			vector<string> names;
			vector<double> ages;
	  };

ostream &operator<< (ostream &os, Name_pair &name_pair)
  {
	if (name_pair.get_names().size() != name_pair.get_ages().size())
	  {
		error("(name, age) pairs size don't match");
	  }

	for (int i = 0 ; i < name_pair.get_names().size() ; ++i)
	  {
		os << "name: " << name_pair.get_names().at(i) << "\t\t" << "Age: " << name_pair.get_ages().at(i) << endl;
	  }

	return os;
  }

bool operator== (const Name_pair &lhs, const Name_pair &rhs)
  {
	if (lhs.get_names().size() != rhs.get_names().size())
	  {
		return false;
	  }
	if (lhs.get_ages().size() != rhs.get_ages().size())
	  {
		return false;
	  }
	for (int i {0} ; i < lhs.get_names().size() ; ++i)
	  {
		if (lhs.get_names().at(i) != rhs.get_names().at(i))
		  {
			return false;
		  }
		if (lhs.get_ages().at(i) != rhs.get_ages().at(i))
		  {
			return false;
		  }
	  }
	return true;
  }

bool operator!= (const Name_pair &lhs, const Name_pair &rhs)
  {
	return !(lhs == rhs);
  }

void Name_pair::read_names ()
  {
	cout << "Please enter some names (s to stop):" << endl;
	for (string s ; cin >> s ;)
	  {
		if (s == "s")
		  {
			break;
		  }
		names.push_back(s);
	  }
  }

void Name_pair::read_ages ()
  {
	for (const auto &n: names)
	  {
		double age;
		cout << "Please enter age for " << n << ": ";
		cin >> age;
		ages.push_back(age);
	  }
  }

//void Name_pair::print ()
//  {
//	for (int i = 0 ; i < names.size() ; ++i)
//	  {
//		cout << "name: " << names.at(i) << "\t\t" << "Age: " << ages.at(i) << endl;
//	  }
//  }

void Name_pair::sort_pairs ()
  {
	vector<string> names_sorted(names);
	sort(names_sorted.begin(), names_sorted.end());

	vector<double> ages_sorted;

	// find index and push_back
	for (const auto &n: names_sorted)
	  {
		for (int i {0} ; i < names.size() ; ++i)
		  {
			if (names[i] == n)
			  {
				ages_sorted.push_back(ages[i]);
			  }
		  }
	  }
	names = names_sorted;
	ages = ages_sorted;
  }

vector<string> Name_pair::get_names () const
  {
	return names;
  }

Vector<double> Name_pair::get_ages () const
  {
	return ages;
  }

int main ()
  {
	Name_pair name_pair;

	name_pair.read_names();
	name_pair.read_ages();

	cout << "--- unsorted ---" << endl;
	cout << name_pair;

	Name_pair np1 = name_pair;

	cout << "--- sorted ---" << endl;

	name_pair.sort_pairs();
	cout << name_pair;

	Name_pair np2 = name_pair;

	cout << endl;

	if (np1 == name_pair)
	  {
		cout << "np1 eq name_pair" << endl;
	  }
	else if (np1 != name_pair)
	  {
		cout << "np1 neq name_pair" << endl;
	  }
	else if (np2 == name_pair)
	  {
		cout << "np2 eq name_pair" << endl;
	  }
	else if (np2 != name_pair)
	  {
		cout << "np2 neq name_pair" << endl;
	  }
  }