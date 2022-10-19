//
// Created by martin on 10/18/22.
//

#include "../std_lib.h"

bool not_alpha (char c)
  {
    return !isalnum(c);
  }

template < typename T1, typename T2 >
auto map_swap (map<T1, T2> input_map)
  {
    map<T2, T1> output_map;
    for (auto [key, value] : input_map)
      {
        output_map[value] = key;
      }
    return output_map;
  }

int main (int argc, char *argv[])
  {
    string filename { "../c21/e8.txt" };
    ifstream ifs { filename };
    
    if (!ifs.is_open())
      {
        cerr << "can't open file: " << filename;
      }
    map<string, int> word_count;
    
    for (string line ; !ifs.eof() ; /* */)
      {
        getline(ifs, line);
        auto s { split(line) };
        
        for (auto word : s)
          {
            // remove non alpha characters
            word.erase(remove_if(word.begin(), word.end(), not_alpha), word.end());
            word_count[word]++;
          }
      }
    
    header("Word count map", true);
    
    for (auto [word, count] : word_count)
      {
        cout << setw(12) << left << word << count << endl;
      }
    
    header("Count word map");
    
    auto count_word { map_swap(word_count) };
    
    for (auto iter { count_word.rbegin() } ; iter != count_word.rend() ; ++iter)
      {
        cout << setw(12) << left << iter->second << iter->first << endl;
      }
    
    // hym... a-lot of words with a count of one :-)
    
    return EXIT_SUCCESS;
  }
