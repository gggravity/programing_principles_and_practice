//
// Created by martin on 14/01/2022.
//

#ifndef _MONTH_H_
#define _MONTH_H_

#include "../../std_lib_facilities.h"

enum class Month
	{
		Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
	};

ostream &operator<< (ostream &os, Month m);

Month &operator++ (Month &m);

#endif //_MONTH_H_
