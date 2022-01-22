//
// Created by martin on 19/01/2022.
//

#include "Punctuation_stream.h"

using namespace std;

Punctuation_stream::Punctuation_stream (std::istream &source) : source(source),
																sensitive(true)
  { }

void Punctuation_stream::whitespace (const string &s)
  {

	white = s;
  }

void Punctuation_stream::add_white (char c)
  {

	white += c;
  }

void Punctuation_stream::case_sensitive (bool b)
  {

	sensitive = b;
  }

bool Punctuation_stream::is_case_sensitive ()
  {

	return sensitive;
  }

Punctuation_stream::operator bool ()
  {

	return !(source.fail() || source.bad()) && source.good();
  }

Punctuation_stream &Punctuation_stream::operator>> (std::string &s)
  {

	while (!(buffer >> s))
	  {
		if (buffer.bad() || !source.good())
		  {
			return *this;
		  }
		buffer.clear();

		string line;
		getline(source, line);

		for (int i {0} ; i < line.size() ; ++i)
		  {
			if (is_whitespace(line.at(i)))
			  {
				if (i > 0 && line.at(i) == '-' && isalpha(line.at(i - 1)) && isalpha(line.at(i + 1)))
				  {
					continue;
				  }
				line.at(i) = ' ';
			  }
			else if (!sensitive)
			  {
				line.at(i) = char(tolower(line.at(i)));
			  }
		  }
		buffer.str(line);
	  }
	return *this;
  }

bool Punctuation_stream::is_whitespace (char c)
  {

	for (char &w : white)
	  {
		if (c == w)
		  {
			return true;
		  }
	  }
	return false;
  }
