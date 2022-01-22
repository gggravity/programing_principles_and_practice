//
// Created by martin on 09/01/2022.
//

#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include "../../std_lib_facilities.h"
#include "Variable_type.h"

class Variable
	  {
		public:
			string name;
			double value;
			Variable_type type;

			Variable (string name, double value, Variable_type type);

	  };

#endif //_VARIABLE_H_
