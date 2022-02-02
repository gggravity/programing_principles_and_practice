//
// Created by martin on 02/02/2022.
//

#ifndef _PSEUDO_WINDOW_H_
#define _PSEUDO_WINDOW_H_

#include "Graph.h"

using namespace Graph_lib;

struct Pseudo_window : Shape
      {
            Pseudo_window (Point point_1, Point point_2, int corners = 0);

            Pseudo_window (Point point, int height, int width, int corners = 0);

            [[nodiscard]] int height () const;

            void set_height (int height);

            [[nodiscard]] int width () const;

            void set_width (int width);

            [[nodiscard]] int corners () const;

            void set_corners (int corners);

      protected:
            void draw_lines () const override;

      private:
            int m_height {0};
            int m_width {0};
            int m_corners {0};

      };

#endif //_PSEUDO_WINDOW_H_
