#include <catch2/catch_test_macros.hpp>
#include "../Octagon.h"

using namespace std;
using namespace Graph_lib;

TEST_CASE("No default constructor", "[Octagon]")
  {
	bool default_constructor = is_trivially_constructible<Octagon>::value;
	REQUIRE(!default_constructor);
  }

TEST_CASE("is_default_constructible<Octagon>", "[Octagon]")
  {
	bool idc = is_default_constructible<Octagon>::value;
	REQUIRE(!idc);
  }

TEST_CASE("Two arg constructor", "[Octagon]")
  {
	Octagon o {{400, 400}, 200};
	REQUIRE(o.point(0).x == 600);
	REQUIRE(o.point(0).y == 400);
	REQUIRE(o.point(1).x == 541);
	REQUIRE(o.point(1).y == 258);
	REQUIRE(o.point(2).x == 400);
	REQUIRE(o.point(2).y == 200);
	REQUIRE(o.point(3).x == 258);
	REQUIRE(o.point(3).y == 258);
	REQUIRE(o.point(4).x == 200);
	REQUIRE(o.point(4).y == 400);
	REQUIRE(o.point(5).x == 258);
	REQUIRE(o.point(5).y == 541);
	REQUIRE(o.point(6).x == 399);
	REQUIRE(o.point(6).y == 600);
	REQUIRE(o.point(7).x == 541);
	REQUIRE(o.point(7).y == 541);
	REQUIRE(o.point(8).x == 600);
	REQUIRE(o.point(8).y == 400);
	REQUIRE(o.radius() == 200);
	REQUIRE(o.number_of_points() == 9);
  }

TEST_CASE("radius()", "[Octagon]")
  {
	Octagon octagon_test {{400, 400}, 200};
	REQUIRE(octagon_test.radius() == 200);
  }

TEST_CASE("set_radius()", "[Octagon]")
  {
	Octagon octagon_test {{400, 400}, 200};
	octagon_test.set_radius(400);
	REQUIRE(octagon_test.radius() == 400);
  }

TEST_CASE("is_default_constructible<Shape>", "[Shape]")
  {
	bool idc = is_default_constructible<Graph_lib::Shape>::value;
	REQUIRE(!idc);
  }

TEST_CASE("set_color() and color()", "[Shape]")
  {
	Octagon o {{400, 400}, 200};
	o.set_color(Color::red);
	REQUIRE(o.color().as_int() == 88);
  }

TEST_CASE("set_fill_color() and fill_color()", "[Shape]")
  {
	Octagon o {{400, 400}, 200};
	o.set_fill_color(Color::red);
	REQUIRE(o.fill_color().as_int() == 88);
  }

TEST_CASE("move()", "[Shape]")
  {
	Octagon o {{400, 400}, 200};
	o.move(-100, -100);
	REQUIRE(o.point(0).x == 500);
	REQUIRE(o.point(0).y == 300);
	REQUIRE(o.point(1).x == 441);
	REQUIRE(o.point(1).y == 158);
	REQUIRE(o.point(2).x == 300);
	REQUIRE(o.point(2).y == 100);
	REQUIRE(o.point(3).x == 158);
	REQUIRE(o.point(3).y == 158);
	REQUIRE(o.point(4).x == 100);
	REQUIRE(o.point(4).y == 300);
	REQUIRE(o.point(5).x == 158);
	REQUIRE(o.point(5).y == 441);
	REQUIRE(o.point(6).x == 299);
	REQUIRE(o.point(6).y == 500);
	REQUIRE(o.point(7).x == 441);
	REQUIRE(o.point(7).y == 441);
	REQUIRE(o.point(8).x == 500);
	REQUIRE(o.point(8).y == 300);
  }
