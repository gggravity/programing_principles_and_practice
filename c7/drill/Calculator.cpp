//
// Created by martin on 09/01/2022.
//

#include "Calculator.h"

Token_stream ts;

double Calculator::primary ()
  {
	Token t = ts.get();
	switch (t.kind)
	  {
		case Code::SQRT:
		  return square_root();
		case Code::POWER:
		  return power(t);
		case Code::PARENTHESIS:
		  return parenthesis(t);
		case Code::MINUS:
		  return -primary();
		case Code::NUMBER:
		  return t.value;
		case Code::NAME:
		  return name(t);
		default:
		  error("primary expected");
	  }
  }

double Calculator::term ()
  {
	double left = primary();
	Token t = ts.get();
	while (true)
	  {
		switch (t.kind)
		  {
			case '*':
			  {
				left *= primary();
				t = ts.get();
				break;
			  }
			case '/':
			  {
				divide(left);
				t = ts.get();
				break;
			  }
			default:
			  {
				ts.putback(t);
				return left;
			  }
		  }
	  }
  }

double Calculator::expression ()
  {
	double left = term();
	Token t = ts.get();
	while (true)
	  {
		switch (t.kind)
		  {
			case '+':
			  {
				left += term();
				t = ts.get();
				break;
			  }
			case '-':
			  {
				left -= term();
				t = ts.get();
				break;
			  }
			case '=':
			  error("use of '=' outside of a declaration");
			break;
			default:
			  {
				ts.putback(t);
				return left;
			  }
		  }
	  }
  }

double Calculator::declaration (Variable_type type)
  {
	Token t = ts.get();
	if (t.kind != Code::NAME)
	  {
		cout << "t.kind: " << t.kind << endl;
		error("name expected in declaration");
	  }
	string n = t.name;
//	if (variable_table.is_declared(n))
//	  {
//		error(n, " declared twice");
//	  }
	Token t2 = ts.get();
	if (t2.kind != '=')
	  {
		error("= missing in declaration of ", n);
	  }
	double d = expression();
	variable_table.declare(n, d, type);
	return d;
  }

double Calculator::statement ()
  {
	Token t = ts.get();
	switch (t.kind)
	  {
		case Code::DECLARE:
		  return declaration(VARIABLE);
		case Code::CONSTANT:
		  return declaration(CONSTANT);
		default:
		  ts.putback(t);
		return expression();
	  }
  }

void Calculator::clean_up_mess ()
  {
	ts.ignore(Code::PRINT);
  }

void Calculator::calculate ()
  {
	const string prompt = "> ";
	const string result = "= ";

	while (true)
	  {
		try
		  {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == Code::PRINT)
			  {
				t = ts.get();
			  }
			if (t.kind == Code::QUIT)
			  {
				return;
			  }
			if (t.kind == Code::HELP)
			  {
				help();
				continue;
			  }
			if (t.kind == Code::LIST)
			  {
				variable_table.print();
				continue;
			  }
			ts.putback(t);
			cout << result << statement() << endl;
		  }
		catch (runtime_error &e)
		  {
			cerr << e.what() << endl;
			clean_up_mess();
		  }
	  }
  }

double Calculator::power (Token &t)
  {
	t = ts.get();
	if (t.kind == '(')
	  {
		double lvalue = primary();
		int rvalue = 0;
		t = ts.get();
		if (t.kind == ',')
		  {
			rvalue = int(primary());
		  }
		else
		  {
			error("Second argument is not provided");
		  }
		double result = 1;
		for (double i = 0 ; i < rvalue ; i++)
		  {
			result *= lvalue;
		  }
		t = ts.get();
		if (t.kind != ')')
		  {
			error("')' expected");
		  }
		return result;
	  }
	else
	  {
		error("'(' expected");
	  }
  }

double Calculator::square_root ()
  {
	double d = primary();
	if (d < 0)
	  {
		error("square root of negative number was detected");
	  }
	return sqrt(d);
  }

double Calculator::parenthesis (Token &t)
  {
	double d = expression();
	t = ts.get();
	if (t.kind != ')')
	  {
		error("')' expected");
	  }
	return d;
  }

void Calculator::divide (double &left)
  {
	double d = primary();
	if (d == 0)
	  {
		error("divide by zero");
	  }
	left /= d;
  }

double Calculator::name (Token &t)
  {
	Token t2 = ts.get();
	if (t2.kind == '=')
	  {
		int d = int(expression());
		variable_table.set_value(t.name, d);
		return d;
	  }
	else
	  {
		ts.putback(t2);
		return variable_table.get_value(t.name);
	  }
  }

  void Calculator::help ()
	{
	  cout << "print some help info" << endl;
	}