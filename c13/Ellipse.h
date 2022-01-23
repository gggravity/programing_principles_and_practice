//
// Created by martin on 23/01/2022.
//

#ifndef _ELLIPSE_H_
#define _ELLIPSE_H_

#include "Simple_window.h"
#include "Graph.h"

namespace Shapes
  {

	class Ellipse:
		public Graph_lib::Ellipse
		  {
			public:
				Ellipse (Graph_lib::Point p, int width, int height)
					: Graph_lib::Ellipse(p, width, height)
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
#endif //_ELLIPSE_H_
