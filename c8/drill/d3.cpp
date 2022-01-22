//
// Created by martin on 12/01/2022.
//

#include "../../std_lib_facilities.h"

void print ()
  {
	cout << "global: print()" << endl;
  }

namespace X
  {
	int var;

	void print ()
	  {
		cout << "X: print()" << endl;
	  }
  }

namespace Y
  {
	int var;
  }

namespace Z
  {
	int var;
	void print ()
	  {
		cout << "Z: print()" << endl;
	  }
  }

int main ()
  {
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
	  using Z::var;
	  using Z::print;
	  var = 11;
	  print();
	}
	print();
	X::print();
  }