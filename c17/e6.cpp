#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
  {
    long counter { 0 };
    while (true)
      {
        auto temp = new int(1);
        counter += sizeof(temp);

        if (counter % int(pow(10, 8)) == 0)
          {
            cout << double(counter) / pow(10, 9) << " gigabytes" << endl;
          }
      }

  }