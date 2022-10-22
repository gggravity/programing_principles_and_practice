//
// Created by martin on 10/22/22.
//

#include "../std_lib.h"

using namespace std;

int main (int argc, char *argv[])
  {
    ifstream in { "../c23/dates.txt" };
    
    if (!in)
      {
        cerr << "no file" << endl;
      }
    
    regex pattern { R"((\d{2})([-/\s])?(\d{2})([-/\s])?(\d{4}))" };
    auto line_no { 0 };
    
    for (string line ; getline(in, line) ; /* */)
      {
        ++line_no;
        smatch matches;
        if (regex_search(line, matches, pattern))
          {
            if (matches[2] == matches[4])
              {
                cout << line_no << ": "
                     << matches[1] << "-"
                     << matches[3] << "-"
                     << matches[5] << endl;
              }
          }
      }
    
    return EXIT_SUCCESS;
  }
