#include "../std_lib_facilities.h"

int f (int x, int y, int z);
int area (int length, int width);
char ask_user (string question);
int framed_area (int x, int y);

int main ()
{
//  ask_user("some question");
  cout << area (-1, -1) << endl;
  cout << f (10, 10, 20) << endl;
}

char ask_user (string question)
{
  cout << question << "? (yes or no)";
  string answer = " ";
  cin >> answer;
  if (answer == "y" || answer == "yes")
  {
	return 'y';
  }
  if (answer == "n" || answer == "no")
  {
	return 'n';
  }
  return 'b';
}

int area (int length, int width)
{
  if (length <= 0 || width <= 0)
  {
	return -1;
  }
  return length * width;
}

int f (int x, int y, int z)
{
  int area1 = area(x, y);
  if (area1 <= 0)
  {
	error("non-positive area");
  }
//  int area2 = framed_area(1, z);
  int area3 = framed_area(y, z);
  double ratio = double(area1) / area3;
  cout << "ratio: " << ratio << endl;
  return 0;
}

int framed_area (int x, int y)
{
  constexpr int frame_width = 2;
  if (x - frame_width <= 0 || y - frame_width <= 0)
  {
	error("non-positive area() argument called by framed_area()");
  }
  return area(x - frame_width, y - frame_width);
}