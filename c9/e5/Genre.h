//
// Created by martin on 14/01/2022.
//

#ifndef _GENRE_H_
#define _GENRE_H_

#include "../../std_lib_facilities.h"

enum class Genre
	  {
		Fiction, Nonfiction, Periodical, Biography, Children
	  };

ostream &operator<<(ostream &os, const Genre &genre);

#endif //_GENRE_H_
