//
// Created by martin on 19/01/2022.
//

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main (int argc, char **argv)
  {
	auto *window = new Fl_Window(340, 180);
	auto *box = new Fl_Box(20, 40, 300, 100, "Hello, World!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show(argc, argv);
	return Fl::run();
  }