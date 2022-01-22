//
// Created by martin on 14/01/2022.
//

#include "Transaction.h"

ostream &operator<< (ostream &os, const Transaction &transaction)
  {
	os << "book: " << transaction.book << endl;
	os << "patron: " << transaction.patron << endl;
	os << "date: " << transaction.date;
	return os;
  }
