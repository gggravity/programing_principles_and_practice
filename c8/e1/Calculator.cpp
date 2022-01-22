//
// Created by martin on 09/01/2022.
//

#include "Calculator.h"

double Calculator::primary (Token_stream &ts)
  {
	Token t = ts.get();
	switch (t.kind)
	  {
		case Code::SQRT:
		  return square_root(ts);
		case Code::POWER:
		  return power(ts, t);
		case Code::PARENTHESIS:
		  return parenthesis(ts, t);
		case Code::MINUS:
		  return -primary(ts);
		case Code::NUMBER:
		  return t.value;
		case Code::NAME:
		  return name(ts, t);
		default:
		  error("primary expected");
	  }
	return -1;
  }

double Calculator::term (Token_stream &ts)
  {
	double left = primary(ts);
	Token t = ts.get();
	while (true)
	  {
		switch (t.kind)
		  {
			case '*':
			  {
				left *= primary(ts);
				t = ts.get();
				break;
			  }
			case '/':
			  {
				divide(ts, left);
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

double Calculator::expression (Token_stream &ts)
  {
	double left = term(ts);
	Token t = ts.get();
	while (true)
	  {
		switch (t.kind)
		  {
			case '+':
			  {
				left += term(ts);
				t = ts.get();
				break;
			  }
			case '-':
			  {
				left -= term(ts);
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

double Calculator::declaration (Token_stream &ts, Variable_type type)
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
	double d = expression(ts);
	variable_table.declare(n, d, type);
	return d;
  }

double Calculator::statement (Token_stream &ts)
  {
	Token t = ts.get();
	switch (t.kind)
	  {
		case Code::DECLARE:
		  return declaration(ts, VARIABLE);
		case Code::CONSTANT:
		  return declaration(ts, CONSTANT);
		default:
		  ts.putback(t);
		return expression(ts);
	  }
  }

void Calculator::clean_up_mess (Token_stream &ts)
  {
	ts.ignore(Code::PRINT);
  }

void Calculator::calculate ()
  {
	Token_stream ts;
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
			cout << result << statement(ts) << endl;
		  }
		catch (runtime_error &e)
		  {
			cerr << e.what() << endl;
			clean_up_mess(ts);
		  }
	  }
  }

double Calculator::power (Token_stream &ts, Token &t)
  {
	t = ts.get();
	if (t.kind == '(')
	  {
		double lvalue = primary(ts);
		int rvalue = 0;
		t = ts.get();
		if (t.kind == ',')
		  {
			rvalue = int(primary(ts));
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
	return -1;
  }

double Calculator::square_root (Token_stream &ts)
  {
	double d = primary(ts);
	if (d < 0)
	  {
		error("square root of negative number was detected");
	  }
	return sqrt(d);
  }

double Calculator::parenthesis (Token_stream &ts, Token &t)
  {
	double d = expression(ts);
	t = ts.get();
	if (t.kind != ')')
	  {
		error("')' expected");
	  }
	return d;
  }

void Calculator::divide (Token_stream &ts, double &left)
  {
	double d = primary(ts);
	if (d == 0)
	  {
		error("divide by zero");
	  }
	left /= d;
  }

double Calculator::name (Token_stream &ts, Token &t)
  {
	Token t2 = ts.get();
	if (t2.kind == '=')
	  {
		int d = int(expression(ts));
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