//
// Created by martin on 23/01/2022.
//

#include "Ellipse.h"

namespace Shapes
  {
	Graph_lib::Point Ellipse::n ()
	  {
		return {center().x, center().y - minor()};
	  }

	Graph_lib::Point Ellipse::s ()
	  {
		return {center().x, center().y + minor()};
	  }

	Graph_lib::Point Ellipse::e ()
	  {
		return {center().x + major(), center().y};
	  }

	Graph_lib::Point Ellipse::w ()
	  {
		return {center().x - major(), center().y};
	  }

	Graph_lib::Point Ellipse::center ()
	  {
		return {Graph_lib::Ellipse::center().x, Graph_lib::Ellipse::center().y};
	  }

	Graph_lib::Point Ellipse::ne ()
	  {
		return {center().x + major(), center().y - minor()};
	  }

	Graph_lib::Point Ellipse::se ()
	  {
		return {center().x + major(), center().y + minor()};
	  }

	Graph_lib::Point Ellipse::sw ()
	  {
		return {center().x - major(), center().y + minor()};
	  }

	Graph_lib::Point Ellipse::nw ()
	  {
		return {center().x - major(), center().y - minor()};
	  }
  }