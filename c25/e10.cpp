//
// Created by martin on 10/23/22.
//

#include "../std_lib.h"

struct PPN
{
    unsigned int PFN : 22;
    int: 3;
    unsigned int CCA : 3;
    bool non_reachable : 1;
    bool dirty : 1;
    bool valid : 1;
    bool global : 1;
};

void print_bitfield (struct PPN ppn)
{
  cout << "PFN: " << ppn.PFN << endl;
  cout << "CCA: " << ppn.CCA << endl;
  cout << "non_reachable: " << ppn.non_reachable << endl;
  cout << "dirty: " << ppn.dirty << endl;
  cout << "valid: " << ppn.valid << endl;
  cout << "global: " << ppn.global << endl;
}

int main (int argc, char *argv[])
{
  PPN ppn { };

  header ("part 1", true);

  ppn.PFN = 0;
  ppn.CCA = 0;
  ppn.non_reachable = true;
  ppn.dirty = true;
  ppn.valid = true;
  ppn.global = true;

  print_bitfield (ppn);

  header ("part 2");

  ppn.PFN = 1;
  ppn.CCA = 3;
  ppn.non_reachable = false;
  ppn.dirty = false;
  ppn.valid = true;
  ppn.global = true;

  print_bitfield (ppn);

  header ("part 3 - skipped");

  return EXIT_SUCCESS;
}
