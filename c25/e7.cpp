//
// Created by martin on 10/23/22.
//

#include "../std_lib.h"

int main (int argc, char *argv[])
{
//  for (auto i { 0 } ; i <= 400 ; ++i)
//    {
//      cout << setw (4) << dec << i << setw (4) << hex << "0x" << i << endl;
//    }

  for (auto i { -200 } ; i <= 200 ; ++i)
    {
      cout << setw (4) << dec << i << setw (4) << hex << "0x" << i << endl;
    }

  return EXIT_SUCCESS;
}
