#include <bits/stdc++.h>

using namespace std;

char *strdup (const char *input_string)
  {
    auto pnt_counter = input_string;
    auto pnt_input = input_string;
    int counter { 0 };

    while (*pnt_counter != '\0')
      {
        counter++;
        pnt_counter++;
      }

    auto output_string = new char[counter + 1]; // need space for \0
    auto pnt_output= output_string;

    while(*pnt_input != '\0')
      {
        *pnt_output = *pnt_input;
        pnt_input++;
        pnt_output++;
      }

    return output_string;
  }

int main (int argc, char *argv[])
try
  {
    char c_string[] = "Der var en gang en mand.";

    auto new_string = strdup(c_string);
    cout << new_string << endl;

  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
