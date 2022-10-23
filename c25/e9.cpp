//
// Created by martin on 10/23/22.
//

#include "../std_lib.h"

int main (int argc, char *argv[])
{
  cout << "int is " << sizeof (int) * 8 << " bits" << endl;

  char ch { -1 };

  if (ch == -1)
    {
      cout << "char is signed" << endl;
    }

  return EXIT_SUCCESS;
}
