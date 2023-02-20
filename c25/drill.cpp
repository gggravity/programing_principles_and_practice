//
// Created by martin on 10/23/22.
//

#include "../std_lib.h"

void print_bits (const string &title, short unsigned int number)
{
  bitset<sizeof (number) * 8> a_bitset (number);
  cout << "### " << title << " ###" << endl;
  cout << "dec:" << dec << number << endl;
  cout << "hex: " << hex << number << endl;
  cout << "bin: " << a_bitset << endl << endl;
};

int main (int argc, char *argv[])
{
  int v = 1;
  for (unsigned int i = 0 ; i < sizeof (v) * 8 ; ++i)
    {
      cout << v << endl;
      v <<= 1;
    }

  print_bits ("Every bit set", 0xffff);

  print_bits ("The lowest bit set", 0x1);

  print_bits ("The highest bit set", 0x8000);

  print_bits ("The lowest byte set", 0x000f);

  print_bits ("The highest byte set", 0xf000);

  print_bits ("Every second bit set (lowest = 1)", 0x5555);

  print_bits ("Every second bit set (lowest = 0)", 0xaaaa);

  short unsigned int one { 1 };
  short unsigned int zero { 0 };

  print_bits ("Every bit set", ~zero);

  print_bits ("The lowest bit set", one);

  print_bits ("The highest bit set", one << (sizeof (one) * 8 - 1)); // 15 places

  auto lowest_byte = one;
  lowest_byte <<= 1;
  lowest_byte |= one;
  lowest_byte <<= 1;
  lowest_byte |= one;
  lowest_byte <<= 1;
  lowest_byte |= one;
  print_bits ("The lowest byte set", lowest_byte);


  auto highest_byte = lowest_byte << 12; // 4 * 3

  print_bits ("The highest byte set", highest_byte);

  auto stripes_one = one;
  stripes_one <<= 2;
  stripes_one += one;
  stripes_one <<= 2;
  stripes_one += one;
  stripes_one <<= 2;
  stripes_one += one;
  stripes_one <<= 2;
  stripes_one += one;
  stripes_one <<= 2;
  stripes_one += one;
  stripes_one <<= 2;
  stripes_one += one;
  stripes_one <<= 2;
  stripes_one += one;
  print_bits ("Every second bit set (lowest = 1)", stripes_one);

  auto stripes_zero = stripes_one << 1;
  print_bits ("Every second bit set (lowest = 0)", stripes_zero);

  return EXIT_SUCCESS;
}
