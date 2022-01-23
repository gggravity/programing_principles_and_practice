//
// Created by martin on 23/01/2022.
//

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Simple_window.h"
#include "Graph.h"

namespace Shapes
  {
	class Circle:
		public Graph_lib::Circle
		  {
			public:
				Circle (Graph_lib::Point p, int radius)
					: Graph_lib::Circle(p, radius)
				  {

				  }

				Graph_lib::Point n ();

				Graph_lib::Point s ();

				Graph_lib::Point e ();

				Graph_lib::Point w ();

				Graph_lib::Point center ();

				Graph_lib::Point ne ();

				Graph_lib::Point se ();

				Graph_lib::Point sw ();

				Graph_lib::Point nw ();

			private:
				static double to_radian (double degree)
				  {
					return 2 * std::numbers::pi * (degree / 360);
				  }

		  };

  }

#endif //_CIRCLE_H_
