#include "../std_lib_facilities.h"

int main ()
{
  int v1 {0};
  int v2 {0};
  int v3 {0};
  int smallest;
  int middle;
  int largest;

  cout << "Please enter 3 integer values: " << endl;

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
