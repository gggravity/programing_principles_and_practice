//
// Created by martin on 09/01/2022.
//

#include "Variable.h"

Variable::Variable (string name, double value, Variable_type type)
	: name(std::move(name)), value(value), type(type)
  { }
