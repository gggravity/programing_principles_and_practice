//
// Created by martin on 01/02/2022.
//

#ifndef _GROUP_H_
#define _GROUP_H_

#include "std_lib.h"
#include "Graph.h"

using namespace std;

struct Group:
	Graph_lib::Shape
	  {
			Group ();

			virtual void move (int dx, int dy) override;

		protected:
			virtual void draw_lines () const override;

		private:
			static constexpr int board_size {10};
			static constexpr int box_size {30};

			void init_board ();

			void init_blacks ();

			void init_reds ();

			Graph_lib::Vector_ref<Shape> m_board;
			Graph_lib::Vector_ref<Graph_lib::Circle> m_blacks;
			Graph_lib::Vector_ref<Graph_lib::Circle> m_reds;

	  };

#endif //_GROUP_H_
