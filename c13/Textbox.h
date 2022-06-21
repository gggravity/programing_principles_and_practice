//
// Created by martin on 23/01/2022.
//

#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include "Simple_window.h"
#include "Graph.h"

namespace Shapes
  {
	class Textbox:
		public Graph_lib::Shape
		  {
			public:
				Textbox (Graph_lib::Point center, std::string text);

				[[nodiscard]] const std::string &text () const;

				[[nodiscard]] double height () const;

				void set_height (double height);

				[[nodiscard]] double width () const;

				void set_width (double width);

				[[nodiscard]] const Graph_lib::Font &font () const;

				void set_font (const Graph_lib::Font &font);

				int font_size () const;

				void set_font_size (int font_size);

//				void set_fill_color (Graph_lib::Color color);

				Graph_lib::Point north ();

				Graph_lib::Point south ();

				Graph_lib::Point east ();

				Graph_lib::Point west ();

				Graph_lib::Point center ();

				Graph_lib::Point ne ();

				Graph_lib::Point se ();

				Graph_lib::Point sw ();

				Graph_lib::Point nw ();

				int dx () const;

				void set_dx (int dx);

				int dy () const;

				void set_dy (int dy);

				int w () const;

				void set_w (int w);

				int h () const;

				void set_h (int h);

			protected:
				void draw_lines () const override;

			private:
				std::string m_text;
				Graph_lib::Font m_font {fl_font()};
				int m_font_size {(14 < fl_size()) ? fl_size() : 14};    // at least 14 point
				double m_height {0};
				double m_width {0};

			private:
				int m_dx;
				int m_dy;
				int m_w;
				int m_h;
//				Graph_lib::Color fcolor {Graph_lib::Color::invisible};
		  };

  }

#endif //_TEXTBOX_H_
