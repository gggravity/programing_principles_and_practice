//
// Created by martin on 26/01/2022.
//

#ifndef _STRIPPED_RECTANGLE_H_
#define _STRIPPED_RECTANGLE_H_

#include "../../GUI/Graph.h"

using namespace std;
using namespace Graph_lib;

class Stripped_rectangle
	:
		public Rectangle
	  {
		public:
			using Rectangle::Rectangle;

			void draw_lines () const override
			  {
				Rectangle::draw_lines();

				for (int i {0} ; i < height() ; i += 4)
				  {
					fl_line(point(0).x, point(0).y + i, point(0).x + width() - 1, point(0).y + i);
				  }
			  }

		private:
			using Rectangle::set_style;

	  };

#endif //_STRIPPED_RECTANGLE_H_
