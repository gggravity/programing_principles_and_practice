//
// Created by martin on 19/01/2022.
//

#ifndef _PUNCTUATION_STREAM_H_
#define _PUNCTUATION_STREAM_H_

#include "../std_lib.h"

class Punctuation_stream
	  {
		public:
			explicit Punctuation_stream (std::istream &source);

			void whitespace (const std::string &s);

			void add_white (char c);

			bool is_whitespace(char c);

			void case_sensitive (bool b);

			bool is_case_sensitive ();

			Punctuation_stream &operator>> (std::string &s);

			operator bool ();

		private:
			std::istream &source;
			std::istringstream buffer;
			std::string white {";:,.?!()\"{}<>/&$@#%^*|~"};
			bool sensitive;
	  };

#endif //_PUNCTUATION_STREAM_H_
