#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
  {
    cout << "Input some text (! to quit):" << endl;
    vector<char> vc;
    for (char ch;  ch != '!'; cin >> ch)
      {
        vc.push_back(ch);
      }

    cout << "You entered " << vc.size() << " characters." << endl;
  }
