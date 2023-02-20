//
// Created by martin on 23/01/2022.
//

#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include "Simple_window.h"
#include "Graph.h"

struct BoundingBox
	{
		int dx {0};
		int dy {0};
		int w {0};
		int h {0};
	};

namespace Shapes
  {
	class Textbox:
		public Graph_lib::Shape
		  {
			public:
				Textbox (Graph_lib::Point center, std::string text);

				[[nodiscard]] const std::string &label () const;

				[[nodiscard]] int height () const;

				void set_height (int height);

				[[nodiscard]] int width () const;

				void set_width (int width);

				[[nodiscard]] const Graph_lib::Font &font () const;

				void set_font (const Graph_lib::Font &font);

				[[nodiscard]] int font_size () const;

				Graph_lib::Point as_point();

				void set_font_size (int font_size);

//				void set_fill_color (Graph_lib::Color color);

				[[nodiscard]] BoundingBox get_bounding_box () const;

			protected:
				void draw_lines () const override;

			private:
				std::string m_text;
				Graph_lib::Font m_font {fl_font()};
				int m_font_size {(14 < fl_size()) ? fl_size() : 14};    // at least 14 point
				int m_height {0};
				int m_width {0};

//				Graph_lib::Color fcolor {Graph_lib::Color::invisible};
		  };

	Graph_lib::Point north (Textbox &textbox);

	Graph_lib::Point south (Textbox &textbox);

	Graph_lib::Point east (Textbox &textbox);

	Graph_lib::Point west (Textbox &textbox);

	Graph_lib::Point center (Textbox &textbox);

	Graph_lib::Point ne (Textbox &textbox);

	Graph_lib::Point se (Textbox &textbox);

	Graph_lib::Point sw (Textbox &textbox);

	Graph_lib::Point nw (Textbox &textbox);
  }

#endif //_TEXTBOX_H_
