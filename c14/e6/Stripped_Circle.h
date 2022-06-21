//
// Created by martin on 26/01/2022.
//

#ifndef _STRIPPED_CIRCLE_H_
#define _STRIPPED_CIRCLE_H_

#include "../../GUI/Graph.h"

using namespace std;
using namespace Graph_lib;

class Stripped_Circle
	:
		public Circle
	  {
		public:
			using Circle::Circle;

			void draw_lines () const override
			  {
				Circle::draw_lines();

				for (int y = point(0).y ; y < point(0).y + 2 * radius() ; y += 4)
				  {
					int x1 = int(center().x - sqrt(pow(radius(), 2) - pow(center().y - y, 2)));
					int x2 = int(center().x + sqrt(pow(radius(), 2) - pow(center().y - y, 2)));
					fl_line(x1, y, x2, y);
				  }
			  }

		private:
			using Circle::set_style;

	  };

#endif //_STRIPPED_CIRCLE_H_
