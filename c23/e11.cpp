//
// Created by martin on 10/22/22.
//

#include <ranges>

#include "../std_lib.h"

using namespace terminal_colors;

struct Count
    {
        int boys;
        int girls;
        int total;
        
        bool operator== (const Count &rhs) const
          {
            return boys == rhs.boys &&
                   girls == rhs.girls &&
                   total == rhs.total;
          }
        
        bool operator!= (const Count &rhs) const
          {
            return !( rhs == *this );
          }
    };

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

int klasse_to_year (const string &klasse)
  {
    regex pattern { R"(^\d{1,2})" };
    smatch matches;
    if (regex_search(klasse, matches, pattern))
      {
        return stoi(matches[0]);
      }
    return -1;
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
    
    map<int, Count> map_count;
    
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
        if (isdigit(matches[1].str()[0])) // skip REST and "Alle klasser"
          {
            auto year = klasse_to_year(matches[1]);
            map_count[year].boys += current_boy;
            map_count[year].girls += current_girl;
            map_count[year].total += current_total;
          }
      }
    
    cout << "total boys: " << boys << endl;
    cout << "total girls: " << girls << endl;
    cout << "total students: " << boys + girls << endl;
    
    cout << "eof at line: " << line_no << endl;
    
    cout << endl << "### count ###" << endl;
    
    for (auto [year, count] : map_count)
      {
        cout << year << "\t"
             << count.boys << "\t"
             << count.girls << "\t"
             << count.total << endl;
      }
    
    cout << endl << "### changes ###" << endl;
    
    auto previous = Count { -1, -1, -1 };
    for (auto [year, count] : map_count)
      {
        if (previous == Count { -1, -1, -1 })
          {
            cout << "Skipping first year..." << endl;
          }
        else
          {
            auto change = Count {
                count.boys - previous.boys,
                count.girls - previous.girls,
                count.total - previous.total };
            
            cout << year << "\t"
                 << ( change.boys >= 0 ? green(to_string(change.boys)) : red(to_string(change.boys)) ) << "\t"
                 << ( change.girls >= 0 ? green(to_string(change.girls)) : red(to_string(change.girls)) ) << "\t"
                 << ( change.total >= 0 ? green(to_string(change.total)) : red(to_string(change.total)) ) << "\t"
                 << endl;
          }
        previous = Count { count.boys, count.girls, count.total };
      }
    
    return EXIT_SUCCESS;
  }
