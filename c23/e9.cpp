//
// Created by martin on 10/22/22.
//

#include "../std_lib.h"

template < typename T >
T from_string (const string &s)
  {
    istringstream iss { s };
    T t;
    if (!( iss >> t ))
      {
        throw runtime_error("from_string error");
      }
    return t;
  }

int main (int argc, char *argv[])
  {
    ifstream ifs { "../c23/table.txt" };
    if (!ifs)
      {
        throw runtime_error("input file not found");
      }
    
    string line;
    int line_no { 0 };
    
    regex header { R"(^[\w ]+(\t[\w ]+)*$)" };
    regex row { R"(^([\w ]+)\t(\d+)\t(\d+)\t(\d+)$)" };
    
    if (getline(ifs, line))
      {
        ++line_no;
        smatch matches;
        if (!regex_match(line, matches, header))
          {
            throw runtime_error("no header found");
          }
      }
    
    auto boys { 0 };
    auto girls { 0 };
    
    while (getline(ifs, line))
      {
        ++line_no;
        smatch matches;
        if (!regex_match(line, matches, row))
          {
            throw runtime_error("bad line: " + to_string(line_no));
          }
        
        auto current_boy { from_string<int>(matches[2]) };
        auto current_girl { from_string<int>(matches[3]) };
        auto current_total { from_string<int>(matches[4]) };
        
        if (current_boy + current_girl != current_total)
          {
            throw runtime_error("bad row sum");
          }
        
        if (matches[1] == "Alle klasser")
          {
            if (current_boy != boys)
              {
                throw runtime_error("boys don't add up");
              }
            if (current_girl != girls)
              {
                throw runtime_error("girls don't add up");
              }
            if (!( ifs >> ws ).eof())
              {
                throw runtime_error("characters after total line");
              }
          }
        else
          {
            boys += current_boy;
            girls += current_girl;
          }
      }
    
    cout << "total boys: " << boys << endl;
    cout << "total girls: " << girls << endl;
    cout << "total students: " << boys + girls << endl;
    
    cout << "eof at line: " << line_no << endl;
    
    return EXIT_SUCCESS;
  }
