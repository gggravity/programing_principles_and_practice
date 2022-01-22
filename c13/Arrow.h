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
				Arrow (Graph_lib::Point p1, Graph_lib::Point p2, int arrow_head_length = 10);

			protected:
				void draw_lines () const override;

			private:

		  };
  }
#endif //_ARROW_H_
