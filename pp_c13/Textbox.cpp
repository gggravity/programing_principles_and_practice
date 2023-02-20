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
	//	int dx, dy, w, h;
	// 	fl_text_extents(label().c_str(), dx, dy, w, h);

	BoundingBox bb = get_bounding_box();
//	cout << label().c_str() << " " << bb.dx << " " << bb.dx << endl;
//	cout << label().c_str() << " " << bb.dy << " " << bb.dy << endl;
//	cout << label().c_str() << " " << bb.w << " " << bb.w << endl;
//	cout << label().c_str() << " " << bb.h << " " << bb.h << endl;

	fl_color(fill_color().as_int());
	fl_rectf(point(0).x + bb.dx - 10, point(0).y + bb.dy - 10, bb.w + 20, bb.h + 20);
	fl_color(color().as_int());
	fl_rect(point(0).x + bb.dx - 10, point(0).y + bb.dy - 10, bb.w + 20, bb.h + 20);

	fl_draw(label().c_str(), point(0).x, point(0).y);
	fl_font(original_font, original_size);

  }

const std::string &Shapes::Textbox::label () const
  {
	return m_text;
  }

int Shapes::Textbox::height () const
  {
	return m_height;
  }

void Shapes::Textbox::set_height (int height)
  {
	Textbox::m_height = height;
  }

int Shapes::Textbox::width () const
  {
	return m_width;
  }

void Shapes::Textbox::set_width (int width)
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

BoundingBox Shapes::Textbox::get_bounding_box () const
  {
	BoundingBox bb;

	int original_font = fl_font();
	int original_size = fl_size();
	fl_font(font().as_int(), font_size());

	fl_text_extents(label().c_str(), bb.dx, bb.dy, bb.w, bb.h);

	fl_font(original_font, original_size);

	return bb;
  }

Graph_lib::Point Shapes::Textbox::as_point ()
  {
	return {point(0).x, point(0).y};
  }

/// Helpers below

Graph_lib::Point Shapes::north (Textbox &textbox)
  {
	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x + bb.w / 2, textbox.as_point().y - bb.h + bb.dy};
  }

Graph_lib::Point Shapes::south (Textbox &textbox)
  {
	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x + bb.w / 2, textbox.as_point().y - bb.dy};
  }

Graph_lib::Point Shapes::east (Textbox &textbox)
  {
	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x + bb.w, textbox.as_point().y - bb.h / 2};
  }

Graph_lib::Point Shapes::west (Textbox &textbox)
  {
	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x, textbox.as_point().y - bb.h / 2};
  }

Graph_lib::Point Shapes::center (Textbox &textbox)
  {
	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x + bb.w / 2, textbox.as_point().y - bb.h / 2};
  }

Graph_lib::Point Shapes::ne (Textbox &textbox)
  {
	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x + bb.w, textbox.as_point().y - bb.h};
  }

Graph_lib::Point Shapes::se (Textbox &textbox)
  {
	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x + bb.w, textbox.as_point().y};
  }

Graph_lib::Point Shapes::sw (Textbox &textbox)
  {
//	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x, textbox.as_point().y};
  }

Graph_lib::Point Shapes::nw (Textbox &textbox)
  {
	BoundingBox bb = textbox.get_bounding_box();
	return {textbox.as_point().x, textbox.as_point().y - bb.h};
  }