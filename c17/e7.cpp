#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
  {
    cout << "Input some text (! to quit):" << endl;
    char ch;
    auto counter { 0 };
    auto char_array = new char[1000];

    while (cin >> ch && ch != '!')
      {
        char_array[counter] = ch;
        counter++;
      }

      cout << "You entered " << counter << " characters." << endl;
  }
