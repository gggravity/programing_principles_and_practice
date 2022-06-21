//
// Created by martin on 23/01/2022.
//

#ifndef _E4_SOURCE_H_
#define _E4_SOURCE_H_

#include "Simple_window.h"
#include "Graph.h"

namespace Shapes
  {
	Graph_lib::Point n (Graph_lib::Rectangle const &rectangle);

	Graph_lib::Point s (Graph_lib::Rectangle const &rectangle);

	Graph_lib::Point e (Graph_lib::Rectangle const &rectangle);

	Graph_lib::Point w (Graph_lib::Rectangle const &rectangle);

	Graph_lib::Point center (Graph_lib::Rectangle const &rectangle);

	Graph_lib::Point ne (Graph_lib::Rectangle const &rectangle);

	Graph_lib::Point se (Graph_lib::Rectangle const &rectangle);

	Graph_lib::Point sw (Graph_lib::Rectangle const &rectangle);

	Graph_lib::Point nw (Graph_lib::Rectangle const &rectangle);
  }

std::ostream &operator<< (std::ostream &os, const Graph_lib::Point &point);

#endif //_E4_SOURCE_H_
