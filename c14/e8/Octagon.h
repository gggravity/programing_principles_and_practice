//
// Created by martin on 27/01/2022.
//

#ifndef _OCTAGON_H_
#define _OCTAGON_H_

#include "Graph.h"

class Octagon
	:
		public Graph_lib::Shape
	  {
		public:
			Octagon (Graph_lib::Point center, int radius);

			[[nodiscard]] int radius () const;

			void set_radius (int radius);

		private:
			static double radians (double degrees);

			int m_radius;

			static Graph_lib::Point point_on_circle (Graph_lib::Point center, int radius, int angle);
	  };

#endif //_OCTAGON_H_
