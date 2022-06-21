//
// Created by martin on 14/01/2022.
//

#ifndef _ISBN_H_
#define _ISBN_H_

#include "../../std_lib_facilities.h"

struct ISBN
	  {
		public:
			ISBN (int n1, int n2, int n3, char c);
			[[nodiscard]] int get_n1() const;
			[[nodiscard]] int get_n2() const;
			[[nodiscard]] int get_n3() const;
			[[nodiscard]] char get_c() const;

		private:
			int n1{};
			int n2{};
			int n3{};
			char c{};
	  };

bool operator== (const ISBN &rhs, const ISBN &lhs);

bool operator!= (const ISBN &rhs, const ISBN &lhs);

ostream &operator<< (ostream &os, const ISBN &isbn);

#endif //_ISBN_H_
