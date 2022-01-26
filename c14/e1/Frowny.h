//
// Created by martin on 26/01/2022.
//

#ifndef _FROWNY_H_
#define _FROWNY_H_

#include "../../GUI/Graph.h"

class Frowny:
	public Graph_lib::Circle
	  {
		public:
			Frowny (Graph_lib::Point point, int radius);

			void draw_lines () const override;

		private:

	  };

#endif //_FROWNY_H_
