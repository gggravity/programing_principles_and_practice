//
// Created by martin on 10/23/22.
//

#include "../std_lib.h"

void print_bits (const string &title, unsigned int number)
{
  cout << "### " << title << " ###" << endl;
  cout << bitset<sizeof (number) * 8> (number) << endl << endl;
};

int main (int argc, char *argv[])
{
  print_bits ("Zero", 0);

  print_bits ("All ones", ~0);

  print_bits ("striped (0 version)", 0xaaaaaaaa);

  print_bits ("striped (1 version)", 0x55555555);

  print_bits ("pattern: 1100", 0xcccccccc);

  print_bits ("pattern: 0011", 0x33333333);

  return EXIT_SUCCESS;
}
