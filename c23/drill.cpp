#include "../std_lib.h"

using namespace std;

int main (int argc, char *argv[])
  {
    ifstream in { "../c22/file.txt" };
    
    if (!in)
      {
        cerr << "no file" << endl;
      }
    
    regex pattern { R"(\w{2}\s*\d{5}(-\d{4})?)" };
    auto line_no { 0 };
    
    for (string line ; getline(in, line) ; /* */)
      {
        ++line_no;
        smatch matches;
        if (regex_search(line, matches, pattern))
          {
            cout << line_no << ": " << matches[0] << endl;
            if (matches.size() > 1 && matches[1].matched)
              {
                cout << "\t: " << matches[1] << endl;
              }
          }
      }
    
    return EXIT_SUCCESS;
  }
