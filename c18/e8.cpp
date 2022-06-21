#include <bits/stdc++.h>

using namespace std;

bool is_palindrome (const string &string)
  {
    auto reverse_string = string;
    reverse(reverse_string.begin(), reverse_string.end());

    for (size_t i { 0 } ; i < string.size() ; ++i)
      {
        if (string[i] != reverse_string[i])
          {
            return false;
          }
      }
    return true;
  }

bool is_palindrome (const char s[], int n)
  {
    auto new_string = new char[n + 1];

    for (int i { 0 }, j { n - 1 } ; i < n ; ++i, --j)
      {
        new_string[i] = s[j];
      }

    for (int i { 0 } ; i < n ; ++i)
      {
        if (s[i] != new_string[i])
          {
            return false;
          }
      }
    return true;
  }

bool is_palindrome (const char *first, const char *last)
  {
    auto n = last - first;
    auto counter { 0 };
    auto new_string = new char[n];

    while (last >= first)
      {
        *new_string = *last;
        last--;
        new_string++;
      }
    new_string -= n;
    while (*first == *new_string)
      {
        first++;
        new_string++;
        counter++;
      }

    return counter == n + 1;
  }

int main (int argc, char *argv[])
try
  {
    cout << "bool is_palindrome (const string &string)" << endl;
    cout << is_palindrome("anna") << endl;
    cout << is_palindrome("petep") << endl;
    cout << is_palindrome("malayalam") << endl;
    cout << is_palindrome("ida") << endl;
    cout << is_palindrome("homesick") << endl;
    cout << is_palindrome("home") << endl;

    cout << "bool is_palindrome (const char s[], int n)" << endl;
    cout << is_palindrome("anna", 4) << endl;
    cout << is_palindrome("petep", 5) << endl;
    cout << is_palindrome("malayalam", 9) << endl;
    cout << is_palindrome("ida", 3) << endl;
    cout << is_palindrome("homesick", 8) << endl;
    cout << is_palindrome("home", 8) << endl;

    cout << "bool is_palindrome (const char *first, const char* last)" << endl;
    auto p1 = "anna";
    auto p2 = "petep";
    auto p3 = "malayalam";
    auto p4 = "ida";
    auto p5 = "homesick";
    auto p6 = "home";

    cout << is_palindrome(p1, p1 + strlen(p1)) << endl;
    cout << is_palindrome(p2, p2 + strlen(p2)) << endl;
    cout << is_palindrome(p3, p3 + strlen(p3)) << endl;
    cout << is_palindrome(p4, p4 + strlen(p4)) << endl;
    cout << is_palindrome(p5, p5 + strlen(p5)) << endl;
    cout << is_palindrome(p6, p6 + strlen(p6)) << endl;

  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
