//
// Created by martin on 09/01/2022.
//

#ifndef _VARIABLE_TABLE_H_
#define _VARIABLE_TABLE_H_

#include "../../std_lib_facilities.h"
#include "Variable.h"

class Variable_table
	  {
		public:
			double get_value (const string &s);
			void set_value (const string &s, double d);
			bool is_declared (const string &s);
			double declare(const string& name, double value, Variable_type type);
			void print ();

			Variable_table ();

		private:
			vector<Variable> var_table;
	  };

#endif //_VARIABLE_TABLE_H_
