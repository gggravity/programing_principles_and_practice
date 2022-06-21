//
// Created by martin on 09/01/2022.
//

#include "Variable_table.h"

double Variable_table::get_value (const string &s)
  {
	for (const auto &var: var_table)
	  {
		if (var.name == s)
		  {
			return var.value;
		  }
	  }
	error("get: undefined name ", s);
  }

void Variable_table::set_value (const string &s, double d)
  {
	for (auto &var: var_table)
	  {
		if (var.name == s && var.type == Variable_type::VARIABLE)
		  {
			var.value = d;
			return;
		  }
		else if (var.name == s && var.type == Variable_type::CONSTANT)
		  {
			error(s, " is constant");
		  }
	  }
	error("set: undefined name ", s);
  }

bool Variable_table::is_declared (const string &s)
  {
	for (int i = 0 ; i < var_table.size() ; ++i)
	  {
		if (var_table[i].name == s)
		  {
			return true;
		  }
	  }
	return false;
//	any_of(var_table.begin(),
//		   var_table.end(),
//		   [s] (const Variable &var)
//			 {
//				 return var.name == s;
//			 }
//	);
  }

double Variable_table::declare (const string &name, double value, Variable_type type)
  {
	if (is_declared(name))
	  {
		error(name, " declared twice");
	  }
//	cout << "declaring: " << name << " " << type << endl;
	var_table.push_back(Variable(name, value, type));

	return value;
  }

void Variable_table::print ()
  {
	for (const auto& v: var_table)
	  {
		cout << v.name << "\t\t" << v.value << "\t\t" << v.type << endl;
	  }
  }

Variable_table::Variable_table ()
  {
	// predefine names:
	declare("pi", 3.1415926535, Variable_type::CONSTANT);
	declare("e", 2.7182818284, Variable_type::CONSTANT);
	declare("k", 1000, Variable_type::CONSTANT);
  }
