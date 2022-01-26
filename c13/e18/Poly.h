//
// Created by martin on 26/01/2022.
//

#ifndef _POLY_H_
#define _POLY_H_

#include "../../GUI/Simple_window.h"
#include "../../GUI/std_lib.h"

class Poly
	:
		public Graph_lib::Shape
	  {
		public:
			Poly(std::initializer_list<Graph_lib::Point> points);

		private:

	  };

#endif //_POLY_H_
