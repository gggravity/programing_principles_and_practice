//
// Created by martin on 26/01/2022.
//

#ifndef _SMILEY_H_
#define _SMILEY_H_

#include "../../GUI/Graph.h"

class Smiley
	:
		public Graph_lib::Circle
	  {
		public:
			Smiley (Graph_lib::Point point, int radius);

			void draw_lines () const override;

		private:
	  };

#endif //_SMILEY_H_
