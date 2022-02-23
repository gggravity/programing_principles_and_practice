#include <bits/stdc++.h>

using namespace std;

int is_palindrome (const char s[], int n)
  {
    int first = 0;
    int last = n - 1;
    while (first < last)
      {
        if (s[first] != s[last])
          {
            return false;
          }
        ++first;
        --last;
      }
    return true;
  }

istream &read_word (istream &is, char *buffer, int max)
  {
    is.width(max);
    is >> buffer;
    if (strlen(buffer) == max - 1)
      {
        cerr << "String to long, breaking it up." << endl;

        for (char ch {0} ; ch != '\n'; is.get(ch) )
          {
            // skip the rest of the string.
          }
      }
    return is;
  }

int main (int argc, char *argv[])
try
  {
    constexpr int max = 128;
    for (char s[max] ; read_word(cin, s, max) ;)
      {
        cout << s << " is";
        if (!is_palindrome(s, int(strlen(s))))
          {
            cout << " not";
          }
        cout << " a palindrome" << endl;
      }
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }

