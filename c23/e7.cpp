//
// Created by martin on 10/22/22.
//

#include "../std_lib.h"

using namespace std;

//American Express 34 or 37
//Discover 65, 644, 6011

int is_prefix (const string &line, const string &prefix)
  {
    regex pattern { "^" + prefix };
    smatch matches;
    
    if (regex_search(line, matches, pattern))
      {
        return int(prefix.size());
      }
    return 0;
  }

bool is_discovery (const string &card_string)
  {
    vector<string> prefixes { "65", "644", "6011" };
    for (auto const &prefix : prefixes)
      {
        if (is_prefix(card_string, prefix))
          {
            return true;
          }
      }
    return false;
  }

bool is_american_express (const string &card_string)
  {
    vector<string> prefixes { "34", "37" };
    for (auto const &prefix : prefixes)
      {
        if (is_prefix(card_string, prefix))
          {
            return true;
          }
      }
    return false;
  }

int main (int argc, char *argv[])
  {
    ifstream in { "../c23/cc.txt" };
    
    if (!in)
      {
        cerr << "no file" << endl;
      }
    
    regex pattern { R"((\d{4})-?(\d{4})-?(\d{4})-?(\d{2,4}))" };
    auto line_no { 0 };
    
    for (string line ; getline(in, line) ; /* */)
      {
        ++line_no;
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        smatch matches;
        if (regex_match(line, matches, pattern))
          {
            if (is_discovery(matches[1]))
              {
                cout << "Found a Discovery card: "
                     << matches[1] << " "
                     << matches[2] << " "
                     << matches[3] << " "
                     << matches[4] << endl;
              }
            if (is_american_express(matches[1]))
              {
                cout << "Found a American Express card: "
                     << matches[1] << " "
                     << matches[2] << " "
                     << matches[3] << " "
                     << matches[4] << endl;
              }
          }
      }
    
    return EXIT_SUCCESS;
  }
