#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
  {
    cout << "Input some text (! to quit):" << endl;
    char ch;
    constexpr int max { 50 };
    auto counter { 0 };
    auto char_array = new char[max];

    while (cin >> ch && ch != '!')
      {
        if (counter == max)
          {
            break;
          }
        char_array[counter] = ch;
        counter++;
      }

    cout << "You entered " << counter << " characters." << endl;
  }
