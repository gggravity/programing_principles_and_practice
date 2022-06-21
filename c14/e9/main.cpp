#include "Simple_window.h"
#include "std_lib.h"
#include "Group.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window window {{0, 0}, x_max(), y_max(), "Exercise 9"};

	Group board;

	board.move_piece(Direction::DOWN, Piece_color::BLACK, 5);

	board.move_piece(Direction::UP, Piece_color::RED, 14);
	board.move_piece(Direction::UP, Piece_color::RED, 14);
	board.move_piece(Direction::UP, Piece_color::RED, 14);
	board.move_piece(Direction::LEFT, Piece_color::RED, 14);

	board.move_piece(Direction::UP, Piece_color::RED, 3);
	board.move_piece(Direction::UP, Piece_color::RED, 3);
	board.move_piece(Direction::UP, Piece_color::RED, 3);
	board.move_piece(Direction::RIGHT, Piece_color::RED, 3);

	window.attach(board);

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



