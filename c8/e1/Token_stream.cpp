//
// Created by martin on 09/01/2022.
//

#include "Token_stream.h"

Token_stream::Token_stream ()
	:
	full(false),
	buffer(0)
  { }

Token_stream::Token_stream (istream &)
	:
	full(false),
	buffer(0)
  { }

Token Token_stream::get ()
  {
	if (full)
	  {
		full = false;
		return buffer;
	  }
	char ch;
	cin.get(ch);

	while (isspace(ch))
	  {
		if (ch == '\n')
		  {
			return {Code::PRINT};
		  }
		cin.get(ch);
	  }

	switch (ch)
	  {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
		case ',':
		  return {ch};
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		  {
			cin.putback(ch);
			double val;
			cin >> val;
			return {Code::NUMBER, val};
		  }
		default:
		  if (isalpha(ch))
			{
			  string s;
			  s += ch;
			  while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				{
				  s += ch;
				}
			  cin.putback(ch);

			  if (s == Key::DECLARE)
				{
				  return {Code::DECLARE};
				}
			  if (s == Key::CONSTANT)
				{
				  return {Code::CONSTANT};
				}
			  if (s == Key::QUIT || s == Key::EXIT)
				{
				  return {Code::QUIT};
				}
			  if (s == Key::SQRT)
				{
				  return {Code::SQRT};
				}
			  if (s == Key::POWER)
				{
				  return {Code::POWER};
				}
			  if (s == Key::HELP)
				{
				  return {Code::HELP};
				}
			  if (s == Key::LIST)
				{
				  return {Code::LIST};
				}
			  return {Code::NAME, s};

			}
		error("Bad token");
	  }
  }

void Token_stream::ignore (char c)
  {
	if (full && c == buffer.kind)
	  {
		full = false;
		return;
	  }
	full = false;

	char ch;
	while (cin >> ch)
	  {
		if (ch == c)
		  {
			return;
		  }
	  }
  }

void Token_stream::putback (Token t)
  {
	buffer = std::move(t);
	full = true;
  }

