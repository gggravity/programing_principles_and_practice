#include <bits/stdc++.h>
#include "God.h"

using namespace std;

int main (int argc, char *argv[])
  {
    God *god_list = new God { "Zeus", "Greek", "", "lightning" };
    god_list = god_list->insert(new God { "Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir" });

    print_all(god_list);
    cout << "\n";

  }
