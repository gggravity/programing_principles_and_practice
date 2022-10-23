//
// Created by martin on 10/23/22.
//

#include "../std_lib.h"

int main (int argc, char *argv[])
{
  string keyboard = "½1234567890+qwertyuiopåäsdfghjklæø'<zxcvbnm,.-";

  cout << keyboard << endl;

  for (auto key : keyboard)
    {
      cout << key << setw (6) << int (key) << endl;
    }

  return EXIT_SUCCESS;
}
