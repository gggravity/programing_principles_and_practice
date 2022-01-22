//
// Created by martin on 21/01/2022.
//

#ifndef _BOX_H_
#define _BOX_H_

#include "Simple_window.h"
#include "Graph.h"

namespace Shapes
  {
	class Box:
		public Graph_lib::Shape
		  {
			public:
				Box (Graph_lib::Point point_1, Graph_lib::Point point_2, int corners = 0);

				Box (Graph_lib::Point point, int height, int width, int corners = 0);

				[[nodiscard]] int height () const;

				void set_height (int height);

				[[nodiscard]] int width () const;

				void set_width (int width);

				int corners () const;

				void set_corners (int corners);

			protected:
				void draw_lines () const override;

			private:
				int m_height {0};
				int m_width {0};
				int m_corners {0};
		  };
  }

#endif //_BOX_H_
