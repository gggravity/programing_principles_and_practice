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

			double primary ();

			double term ();

			double expression ();

			double declaration (Variable_type type);

			double statement ();

			// Helper functions below.

			static void clean_up_mess ();

			Variable_table variable_table;

			double power (Token &t);

			double square_root ();

			double parenthesis (Token &t);

			void divide (double &left);

			double name (Token &t);

			static void help ();

	  };

#endif //_CALCULATOR_H_
