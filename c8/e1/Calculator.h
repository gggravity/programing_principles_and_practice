//
// Created by martin on 09/01/2022.
//

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

//#include "../../std_lib_facilities.h"
//#include "Globals.h"
#include "Code.h"
#include "Token_stream.h"
#include "Variable_table.h"

class Calculator
	  {
		public:
			void calculate ();

		private:

			double primary (Token_stream &ts);

			double term (Token_stream &ts);

			double expression (Token_stream &ts);

			double declaration (Token_stream &ts, Variable_type type);

			double statement (Token_stream &ts);

			// Helper functions below.

			static void clean_up_mess (Token_stream &ts);

			Variable_table variable_table;

			double power (Token_stream &ts,Token &t);

			double square_root (Token_stream &ts);

			double parenthesis (Token_stream &ts, Token &t);

			void divide (Token_stream &ts, double &left);

			double name (Token_stream &ts, Token &t);

			static void help ();

	  };

#endif //_CALCULATOR_H_
