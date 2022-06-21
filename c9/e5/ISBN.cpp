//
// Created by martin on 14/01/2022.
//

#include "ISBN.h"

ISBN::ISBN (int n1, int n2, int n3, char c) :
	n1 {n1},
	n2 {n2},
	n3 {n3},
	c {c}
  {

  }

int ISBN::get_n1 () const
  {
	return n1;
  }

int ISBN::get_n2 () const
  {
	return n2;
  }

int ISBN::get_n3 () const
  {
	return n3;
  }

char ISBN::get_c () const
  {
	return c;
  }

bool operator== (const ISBN &rhs, const ISBN &lhs)
  {
	if (rhs.get_n1() != lhs.get_n1())
	  {
		return false;
	  }
	if (rhs.get_n2() != lhs.get_n2())
	  {
		return false;
	  }
	if (rhs.get_n3() != lhs.get_n3())
	  {
		return false;
	  }
	if (rhs.get_c() != lhs.get_c())
	  {
		return false;
	  }
	return true;
  }

bool operator!= (const ISBN &rhs, const ISBN &lhs)
  {
	return !(lhs == rhs);
  }

ostream &operator<< (ostream &os, const ISBN &isbn)
  {
	return os << isbn.get_n1()
			  << isbn.get_n2()
			  << isbn.get_n3()
			  << isbn.get_c();
  }

