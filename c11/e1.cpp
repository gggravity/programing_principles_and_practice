//
// Created by martin on 18/01/2022.
//

#include <fstream>
#include <iostream>

int main ()
  {
	std::string name {"Makefile"};
	std::fstream fs {name, std::ios_base::in};

	if (!fs)
	  {
		std::cerr << "Error: can't open file ('" << name << "')" << std::endl;
		exit(EXIT_FAILURE);
	  }

	while (!fs.eof())
	  {
		char ch;
		fs.get(ch);
		ch = char(tolower(ch));
		std::cout << ch;
	  }
  }
