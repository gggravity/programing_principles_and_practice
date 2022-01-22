//
// Created by martin on 10/01/2022.
//

#ifndef _VARIABLE_TYPE_H_
#define _VARIABLE_TYPE_H_

#include "../../std_lib_facilities.h"

enum Variable_type
	{
		CONSTANT, VARIABLE
	};




inline ostream &operator<< (ostream &os, Variable_type type)
  {
	switch (static_cast<int>(type))
	  {
		case Variable_type::CONSTANT :
		  return os << "constant";
		case Variable_type::VARIABLE :
		  return os << "variable";
		default:
		  return os << "Variable_type{" << int(type) << '}';
	  }
  }

#endif //_VARIABLE_TYPE_H_
