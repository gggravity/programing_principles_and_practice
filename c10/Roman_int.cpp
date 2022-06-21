//
// Created by martin on 17/01/2022.
//

#include "../std_lib_facilities.h"
#include "Roman_int.h"

Roman_int::Roman_int () : num {0}
  {
  }

Roman_int::Roman_int (int num) : num(num)
  {
  }

ostream &operator<< (ostream &os, const Roman_int &roman)
  {
	os << roman.as_string();
	return os;
  }

istream &operator>> (istream &is, Roman_int &roman)
  {
	/**
	 * The numerals for 4 (IV) and 9 (IX) are written using "subtractive notation",
	 * where the first symbol (I) is subtracted from the larger one (V, or X),
	 * thus avoiding the clumsier (IIII, and VIIII).
	 * Subtractive notation is also used for , 90 (XC), 400 (CD) and 900 (CM).
	 * These are the only subtractive forms in standard use.
	 */

	string s;
	is >> s;
	reverse(s.begin(), s.end()); // reverse the string to take care of the "subtractive notation".
	char last = '\0';
	for (char ch : s)
	  {
//		cout << ch << endl;
		if (last == 'V' && ch == 'I' || // 4 = IV
			last == 'X' && ch == 'I' || // 9 = IX
			last == 'L' && ch == 'X' || // 40 = XL
			last == 'C' && ch == 'X' || // 90 = CX
			last == 'D' && ch == 'C' || // 400 = CD
			last == 'M' && ch == 'C' // 900 = CM
			)
		  {
//			cout << "HIT -> " << "last: " << last << " ch: " << ch << endl;
			roman.num -= Roman_int::roman_to_int(ch);
		  }
		else
		  {
			roman.num += Roman_int::roman_to_int(ch);
		  }
		last = ch;
	  }
	return is;
  }

bool operator< (const Roman_int &lhs, const Roman_int &rhs)
  {
	return lhs.num < rhs.num;
  }

bool operator> (const Roman_int &lhs, const Roman_int &rhs)
  {
	return rhs < lhs;
  }

bool operator<= (const Roman_int &lhs, const Roman_int &rhs)
  {
	return !(rhs < lhs);
  }

bool operator>= (const Roman_int &lhs, const Roman_int &rhs)
  {
	return !(lhs < rhs);
  }

bool operator== (const Roman_int &lhs, const Roman_int &rhs)
  {
	return lhs.num == rhs.num;
  }

bool operator!= (const Roman_int &lhs, const Roman_int &rhs)
  {
	return !(rhs == lhs);
  }

int Roman_int::get_num () const
  {
	return num;
  }

void Roman_int::set_num (const string &number)
  {

//	Roman_int::num = number;
  }

/** Roman integers to arabic
 *
 * @param c Roman char
 * @return Roman int
 */
int Roman_int::roman_to_int (char c)
  {
	switch (c)
	  {
	case 'I':
	  return 1;
	case 'V':
	  return 5;
	case 'X':
	  return 10;
	case 'L':
	  return 50;
	case 'C':
	  return 100;
	case 'D':
	  return 500;
	case 'M':
	  return 1000;
	default:
	  error("illegal letter used: ", string(1, c));
	  }
	return c;
  }

int Roman_int::as_int () const
  {
	return get_num();
  }

string Roman_int::as_string () const
  {
	/**
	 * The numerals for 4 (IV) and 9 (IX) are written using "subtractive notation",
	 * where the first symbol (I) is subtracted from the larger one (V, or X),
	 * thus avoiding the clumsier (IIII, and VIIII).
	 * Subtractive notation is also used for , 90 (XC), 400 (CD) and 900 (CM).
	 * These are the only subtractive forms in standard use.
	 */

	int value = get_num();
	string s;

	while (value > 0)
	  {
		if (value >= 1000)
		  {
			value -= 1000;
			s += 'M';
		  }
		else if (value >= 900)
		  {
			value -= 900;
			s += "CM";
		  }
		else if (value >= 500)
		  {
			value -= 500;
			s += 'D';
		  }
		else if (value >= 400)
		  {
			value -= 400;
			s += "CD";
		  }
		else if (value >= 100)
		  {
			value -= 100;
			s += 'C';
		  }
		else if (value >= 90)
		  {
			value -= 90;
			s += "XC";
		  }
		else if (value >= 50)
		  {
			value -= 50;
			s += 'L';
		  }
		else if (value >= 40)
		  {
			value -= 40;
			s += "XL";
		  }
		else if (value >= 10)
		  {
			value -= 10;
			s += 'X';
		  }
		else if (value >= 9)
		  {
			value -= 9;
			s += "IX";
		  }
		else if (value >= 5)
		  {
			value -= 5;
			s += 'V';
		  }
		else if (value >= 4)
		  {
			value -= 4;
			s += "IV";
		  }
		else if (value >= 1)
		  {
			value -= 1;
			s += 'I';
		  }
	  }
	return s;
  }

void Roman_int::input_test ()
  {
	map<Roman_int, string> test_map = Roman_int::get_map();

	int fails {0};
	for (const auto &t : test_map)
	  {
//		if (t.second != "CCXLVI")
//		  {
//			continue;
//		  }

		istringstream in(t.second);
		Roman_int r;
		in >> r;
		bool correct = (r.as_string() == t.second);
		if (!correct)
		  {
			fails++;
		  }
		cout << t.first.as_string()
			 << " ("
			 << t.first.as_int()
			 << ")"
			 << " >> "
			 << r.as_string()
			 << " ("
			 << r.as_int()
			 << ")"
			 << " -> "
			 << (correct ? "true" : "false")
			 << endl;
	  }
	cout << "-----------------------------" << endl;
	cout << "fails: " << fails << endl;
  }

void Roman_int::output_test ()
  {
	map<Roman_int, string> test_map = Roman_int::get_map();

	int fails {0};
	for (const auto &t : test_map)
	  {
		bool correct = (t.first.as_string() == t.second);
		if (!correct)
		  {
			fails++;
		  }
		cout << t.first.as_string()
			 << " (" << t.first.as_int()
			 << ")"
			 << " == "
			 << t.second
			 << " -> "
			 << (correct ? "true" : "false")
			 << endl;
	  }
	cout << "-----------------------------" << endl;
	cout << "fails: " << fails << endl;
  }

map<Roman_int, string> &Roman_int::get_map ()
  {
	// Initialized upon first call to the function.
	static map<Roman_int, string> test_map =
		{
			{39,   "XXXIX"},
			{246,  "CCXLVI"},
			{789,  "DCCLXXXIX"},
			{2421, "MMCDXXI"},
			{160,  "CLX"},
			{207,  "CCVII"},
			{1009, "MIX"},
			{1066, "MLXVI"},
			{1776, "MDCCLXXVI"},
			{1918, "MCMXVIII"},
			{1954, "MCMLIV"},
			{2014, "MMXIV"},
			{1000, "M"},
			{2000, "MM"},
			{3000, "MMM"},
			{100,  "C"},
			{200,  "CC"},
			{300,  "CCC"},
			{400,  "CD"},
			{500,  "D"},
			{600,  "DC"},
			{700,  "DCC"},
			{800,  "DCCC"},
			{900,  "CM"},
			{10,   "X"},
			{20,   "XX"},
			{30,   "XXX"},
			{40,   "XL"},
			{50,   "L"},
			{60,   "LX"},
			{70,   "LXX"},
			{80,   "LXXX"},
			{90,   "XC"},
			{1,    "I"},
			{2,    "II"},
			{3,    "III"},
			{4,    "IV"},
			{5,    "V"},
			{6,    "VI"},
			{7,    "VII"},
			{8,    "VIII"},
			{9,    "IX"},
		};
	return test_map;
  }

