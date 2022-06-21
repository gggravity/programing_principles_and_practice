//
// Created by martin on 23/01/2022.
//

#include "Textbox.h"
#include <utility>

using namespace std;

Shapes::Textbox::Textbox (Graph_lib::Point center, std::string text) :
	m_text(std::move(text))
  {
	add(center);
  }

void Shapes::Textbox::draw_lines () const
  {
	int original_font = fl_font();
	int original_size = fl_size();
	fl_font(font().as_int(), font_size());

	//	fl_text_extents(const char *c, int &dx, int &dy, int &w, int &h);
	int dx, dy, w, h;
	fl_text_extents(text().c_str(), dx, dy, w, h);
	set_dx(dx);
	set_dy(dy);
	set_w(w);
	set(h);

	fl_color(fill_color().as_int());
	fl_rectf(point(0).x + dx - 10, point(0).y + dy - 10, w + 20, h + 20);
	fl_color(color().as_int());
	fl_rect(point(0).x + dx - 10, point(0).y + dy - 10, w + 20, h + 20);

	fl_draw(text().c_str(), point(0).x, point(0).y);
	fl_font(original_font, original_size);

  }

const std::string &Shapes::Textbox::text () const
  {
	return m_text;
  }

double Shapes::Textbox::height () const
  {
	return m_height;
  }

void Shapes::Textbox::set_height (double height)
  {
	Textbox::m_height = height;
  }

double Shapes::Textbox::width () const
  {
	return m_width;
  }

void Shapes::Textbox::set_width (double width)
  {
	Textbox::m_width = width;
  }

const Graph_lib::Font &Shapes::Textbox::font () const
  {
	return m_font;
  }

void Shapes::Textbox::set_font (const Graph_lib::Font &font)
  {
	Textbox::m_font = font;
  }

int Shapes::Textbox::font_size () const
  {
	return m_font_size;
  }

void Shapes::Textbox::set_font_size (int font_size)
  {
	Textbox::m_font_size = font_size;
  }

Graph_lib::Point Shapes::Textbox::north ()
  {
	return {point(0).x, point(0).y};
  }

Graph_lib::Point Shapes::Textbox::south ()
  {
	return Graph_lib::Point();
  }

Graph_lib::Point Shapes::Textbox::east ()
  {
	return Graph_lib::Point();
  }

Graph_lib::Point Shapes::Textbox::west ()
  {
	return Graph_lib::Point();
  }

Graph_lib::Point Shapes::Textbox::center ()
  {
	return Graph_lib::Point();
  }

Graph_lib::Point Shapes::Textbox::ne ()
  {
	return Graph_lib::Point();
  }

Graph_lib::Point Shapes::Textbox::se ()
  {
	return Graph_lib::Point();
  }

Graph_lib::Point Shapes::Textbox::sw ()
  {
	return Graph_lib::Point();
  }

Graph_lib::Point Shapes::Textbox::nw ()
  {
	return {point(0).x + dx() - 10, point(0).y + dy() - 10};
  }

int Shapes::Textbox::dx () const
  {
	return m_dx;
  }

void Shapes::Textbox::set_dx (int dx)
  {
	Textbox::m_dx = dx;
  }

int Shapes::Textbox::dy () const
  {
	return m_dy;
  }

void Shapes::Textbox::set_dy (int dy)
  {
	Textbox::m_dy = dy;
  }

int Shapes::Textbox::w () const
  {
	return m_w;
  }

void Shapes::Textbox::set_w (int w)
  {
	Textbox::m_w = w;
  }

int Shapes::Textbox:h () const
  {
	return m_h;
  }

void Shapes::Textbox::set_h (int h)
  {
	Textbox::m_h = h;
  }

//void Shapes::Textbox::set_fill_color (Graph_lib::Color color)
//  {
//	fcolor = color;
//  }
