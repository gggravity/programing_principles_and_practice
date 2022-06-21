//
// Created by martin on 09/01/2022.
//

#ifndef _TOKEN_STREAM_H_
#define _TOKEN_STREAM_H_

#include "Token.h"
#include "Key.h"
#include "Code.h"
//#include "Globals.h"

class Token_stream
	  {
		public:
			Token_stream ();
			Token_stream (istream&);
			Token get ();
			void putback (Token t);
			void ignore (char);

		private:
			bool full;
			Token buffer;
	  };

#endif //_TOKEN_STREAM_H_
