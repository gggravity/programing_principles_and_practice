#include "../std_lib_facilities.h"

// Steinbeck Hemingway Fitzgerald

int main ()
{
  string v1;
  string v2;
  string v3;
  string smallest;
  string middle;
  string largest;

  cout << "Please enter 3 string values: " << endl;

  cin >> v1 >> v2 >> v3;

  if (v1 <= v2 && v1 <= v3)
  {
	smallest = v1;
  }
  else if (v2 <= v1 && v2 <= v3)
  {
	smallest = v2;
  }
  else
  {
	smallest = v3;
  }

  if (v1 >= v2 && v1 >= v3)
  {
	largest = v1;
  }
  else if (v2 >= v1 && v2 >= v3)
  {
	largest = v2;
  }
  else
  {
	largest = v3;
  }

  if (v1 != smallest && v1 != largest)
  {
	middle = v1;
  }
  else if (v2 != smallest && v2 != largest)
  {
	middle = v2;
  }
  else
  {
	middle = v3;
  }

  cout << smallest << ", " << middle << ", " << largest << endl;

}