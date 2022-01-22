//
// Created by martin on 17/01/2022.
//

#ifndef _ROMAN_INT_H_
#define _ROMAN_INT_H_

#include <ostream>

/**
 * Class to deal with roman integers and convert back and forth them and  normal integers.
 * @param set_num
 */

class Roman_int
	  {
		public:
			Roman_int (); /// default constructor

			Roman_int (int num);

			[[nodiscard]] int get_num () const;

			void set_num (const string &number); /// setter for number

			[[nodiscard]] int as_int () const; //!< a member function.

			[[nodiscard]] string as_string () const;

			static int roman_to_int (char c);

			static void input_test ();

			static void output_test ();

			friend ostream &operator<< (ostream &os, const Roman_int &roman);

			friend istream &operator>> (istream &is, Roman_int &roman);

			friend bool operator== (const Roman_int &lhs, const Roman_int &rhs);

			friend bool operator!= (const Roman_int &lhs, const Roman_int &rhs);

			friend bool operator< (const Roman_int &lhs, const Roman_int &rhs);

			friend bool operator> (const Roman_int &lhs, const Roman_int &rhs);

			friend bool operator<= (const Roman_int &lhs, const Roman_int &rhs);

			friend bool operator>= (const Roman_int &lhs, const Roman_int &rhs);

		private:
			int num; ///< Brief description after the member
			static map<Roman_int, string> &get_map ();
	  };

#endif //_ROMAN_INT_H_
