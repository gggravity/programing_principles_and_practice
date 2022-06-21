//
// Created by martin on 14/01/2022.
//

#include "Genre.h"

ostream &operator<<(ostream &os, const Genre &genre)
  {
	switch (genre)
	  {
		case Genre::Fiction:
		  os << "Fiction";
		  break;
		case Genre::Nonfiction:
		  os << "Nonfiction";
		  break;
		case Genre::Periodical:
		  os << "Periodical";
		  break;
		case Genre::Biography:
		  os << "Biography";
		  break;
		case Genre::Children:
		  os << "Children";
		  break;
	  }

	return os;
  }