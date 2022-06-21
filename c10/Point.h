//
// Created by martin on 16/01/2022.
//

#ifndef _POINT_H_
#define _POINT_H_

#include <istream>
#include <ostream>

class Point
	  {
		public:
			Point ();

			Point (double x, double y);

			[[nodiscard]] double get_x () const;

			void set_x (double x);

			[[nodiscard]] double get_y () const;

			void set_y (double y);

			friend std::ostream &operator<< (std::ostream &os, const Point &point);

			friend std::istream &operator>> (std::istream &is, Point &point);

		private:
			double m_x;
			double m_y;
	  };

#endif //_POINT_H_
