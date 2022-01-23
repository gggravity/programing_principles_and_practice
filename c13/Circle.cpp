//
// Created by martin on 23/01/2022.
//

#include "Circle.h"

namespace Shapes
  {
	Graph_lib::Point Circle::n ()
	  {
		return {center().x, center().y - radius()};
	  }

	Graph_lib::Point Circle::s ()
	  {
		return {center().x, center().y + radius()};
	  }

	Graph_lib::Point Circle::e ()
	  {
		return {center().x + radius(), center().y};
	  }

	Graph_lib::Point Circle::w ()
	  {
		return {center().x - radius(), center().y};
	  }

	Graph_lib::Point Circle::center ()
	  {
		return {Graph_lib::Circle::center().x, Graph_lib::Circle::center().y};
	  }

	Graph_lib::Point Circle::ne ()
	  {
		return {static_cast<int>(center().x - radius() * -cos(to_radian(45))),
				static_cast<int>(center().y - radius() * sin(to_radian(45)))};
	  }

	Graph_lib::Point Circle::se ()
	  {
		return {static_cast<int>(center().x + radius() * cos(to_radian(45))),
				static_cast<int>(center().y + radius() * sin(to_radian(45)))};
	  }

	Graph_lib::Point Circle::sw ()
	  {
		return {static_cast<int>(center().x - radius() * cos(to_radian(45))),
				static_cast<int>(center().y + radius() * sin(to_radian(45)))};
	  }

	Graph_lib::Point Circle::nw ()
	  {
		return {static_cast<int>(center().x - radius() * cos(to_radian(45))),
				static_cast<int>(center().y - radius() * sin(to_radian(45)))};
	  }

  }