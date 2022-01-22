//
// Created by martin on 09/01/2022.
//

#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "../../std_lib_facilities.h"

/* a very simple user-defined type */
class Token
	  {
		public:
			char kind;
			double value {};
			string name;

			Token (char ch)
				: kind(ch), value(0)
			  { }
			Token (char ch, double val)
				: kind(ch), value(val)
			  { }

			Token (char ch, string n)
				: kind {ch}, name {std::move(n)}
			  { }
	  };


#endif //_TOKEN_H_
