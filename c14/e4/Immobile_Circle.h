//
// Created by martin on 26/01/2022.
//

#ifndef _IMMOBILE_CIRCLE_H_
#define _IMMOBILE_CIRCLE_H_

#include "../../GUI/Graph.h"

class Immobile_Circle
	:
		public Graph_lib::Circle
	  {
		public:
			using Circle::Circle;

			void move (int dx, int dy) override
			  {
				throw std::runtime_error("Can't move an Immobile Circle.");
			  }

		private:

	  };

#endif //_IMMOBILE_CIRCLE_H_
