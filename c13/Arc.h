//
// Created by martin on 21/01/2022.
//

#include "Simple_window.h"
#include "Graph.h"

#ifndef _ARC_H_
#define _ARC_H_
namespace Shapes
  {
	class Arc:
		public Graph_lib::Shape
		  {
			public:
				Arc (Graph_lib::Point point, int height, int width, double angle_1, double angle_2);

				void draw_lines () const override;

				[[nodiscard]] double angle_1 () const;

				void set_angle_1 (double angle);

				[[nodiscard]] double angle_2 () const;

				void set_angle_2 (double angle);

				[[nodiscard]] int height () const;

				void set_height (int height);

				[[nodiscard]] int width () const;

				void set_width (int width);

			private:
				// The two angles are measured in degrees counterclockwise from
				// 3'o clock and are the starting and ending angle of the arc,
				// a2 must be greater or equal to a1.

				double m_angle_1;
				double m_angle_2;

				int m_height;
				int m_width;

		  };
  }
#endif //_ARC_H_
