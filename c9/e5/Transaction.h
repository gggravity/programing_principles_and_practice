//
// Created by martin on 14/01/2022.
//

#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include "../../std_lib_facilities.h"
#include "Book.h"
#include "Patron.h"
#include "Date.h"

struct Transaction
	{
		Book book;
		Patron patron;
		Date date;
	};

ostream &operator<< (ostream &os, const Transaction &transaction);

#endif //_TRANSACTION_H_
