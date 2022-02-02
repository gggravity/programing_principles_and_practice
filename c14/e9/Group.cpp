//
// Created by martin on 01/02/2022.
//

#include "Group.h"

Group::Group ()
  {
	init_board();
	init_reds();
	init_blacks();

  }

void Group::init_board ()
  {
	for (int i {0} ; i < board_size ; ++i)
	  {
		for (int j {0} ; j < board_size ; ++j)
		  {
			auto *r = new Graph_lib::Rectangle {
				{2 * box_size + i * box_size * 2, 2 * box_size + j * box_size * 2},
				{4 * box_size + i * box_size * 2, 4 * box_size + j * box_size * 2}
			};
			if ((i + j) % 2)
			  {
				r->set_fill_color(Graph_lib::Color::white);
			  }
			else
			  {
				r->set_fill_color(Graph_lib::Color::blue);
			  }
			r->set_color(Graph_lib::Color::invisible);
			m_board.push_back(r);
		  }
	  }
  }

void Group::move (int dx, int dy)
  {
	Shape::move(dx, dy);
  }

void Group::draw_lines () const
  {
	draw_board();
	draw_blacks();
	draw_reds();
	Shape::draw_lines();
  }

void Group::init_blacks ()
  {
	for (int i {0} ; i < board_size ; ++i)
	  {
		for (int j {0} ; j < 3 ; ++j)
		  {
			auto xx = 3 * box_size + i * box_size * 2;
			auto yy = 3 * box_size + j * box_size * 2;
			auto *c = new Graph_lib::Circle {{xx, yy}, box_size};

			if ((i + j) % 2)
			  {
				c->set_fill_color(Graph_lib::Color::dark_yellow);
				c->set_color(Graph_lib::Color::invisible);
			  }
			else
			  {
				delete c;
				continue;
			  }

			m_blacks.push_back(c);
		  }
	  }
  }

void Group::init_reds ()
  {
	for (int i {0} ; i < board_size ; ++i)
	  {
		for (int j {0} ; j < 3 ; ++j)
		  {
			auto xx = 3 * box_size + i * box_size * 2;
			auto yy = 3 * box_size + j * box_size * 2 + (board_size + 4) * box_size;
			auto *c = new Graph_lib::Circle {{xx, yy}, box_size};

			if ((i + j) % 2 == 0)
			  {
				c->set_fill_color(Graph_lib::Color::dark_red);
				c->set_color(Graph_lib::Color::invisible);
			  }
			else
			  {
				delete c;
				continue;
			  }

			m_reds.push_back(c);
		  }
	  }
  }

void Group::draw_board () const
  {
	for (int i {0} ; i < m_board.size() ; ++i)
	  {
		m_board[i].draw();
	  }
  }

void Group::draw_blacks () const
  {
	for (int i {0} ; i < m_blacks.size() ; ++i)
	  {
		m_blacks[i].draw();
	  }
  }

void Group::draw_reds () const
  {
	for (int i {0} ; i < m_reds.size() ; ++i)
	  {
		m_reds[i].draw();
	  }
  }

