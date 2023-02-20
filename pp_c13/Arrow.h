//
// Created by martin on 22/01/2022.
//

#ifndef _ARROW_H_
#define _ARROW_H_

#include "Simple_window.h"
#include "Graph.h"

namespace Shapes
  {
	class Arrow:
		public Graph_lib::Shape
		  {
			public:
				Arrow (Graph_lib::Point p1, Graph_lib::Point p2);

				void add (Graph_lib::Point p1, Graph_lib::Point p2);

				static Graph_lib::Point find_arrow_length (Graph_lib::Point p1, Graph_lib::Point p2);

			protected:
				void draw_lines () const override;

			private:
				static double magnitude (Graph_lib::Point p1, Graph_lib::Point p2);

				static double angle (Graph_lib::Point p1, Graph_lib::Point p2);

				static Graph_lib::Point rotate (Graph_lib::Point p, int angle);

				static Graph_lib::Point get_vector (Graph_lib::Point p1, Graph_lib::Point p2);

				static double to_radian (double degree);

				static double to_degree (double radian);
		  };
  }
#endif //_ARROW_H_
