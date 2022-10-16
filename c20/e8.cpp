//
// Created by martin on 16-10-22.
//

#include "../std_lib.h"

using Line = vector<char>;

struct Text_iterator
  {
    Text_iterator (list<Line>::iterator line_list_iterator, Line::iterator position) :
        ln { line_list_iterator },
        pos { position }
      {
      
      }
    
    char &operator* ()
      {
        return *pos;
      }
    
    Text_iterator &operator++ ()
      {
        ++pos;
        if (pos == ( *ln ).end())
          {
            ++ln;
            pos = ( *ln ).begin();
          }
        return *this;
      }
    
    bool operator== (const Text_iterator &other) const
      {
        return ln == other.ln && pos == other.pos;
      }
    
    bool operator!= (const Text_iterator &other) const
      {
        return !( *this == other );
      }
  
  private:
    list<Line>::iterator ln;
    Line::iterator pos;
  };

struct Document
    {
        list<Line> line;
        
        Document ()
          {
            line.emplace_back();
          }
        
        Text_iterator begin ()
          {
            return { line.begin(), line.begin()->begin() };
          }
        
        Text_iterator end ()
          {
            auto last = line.end();
            --last;
            return { last, last->end() };
          }
        
        friend istream &operator>> (istream &is, Document &document)
          {
            for (char ch ; is.get(ch) ;)
              {
                document.line.back().push_back(ch);
                if (ch == '\n')
                  {
                    document.line.emplace_back();
                  }
              }
            if (!document.line.back().empty())
              {
                document.line.emplace_back();
              }
            
            return is;
          }
    };

void print (Document &document)
  {
    for (auto p : document)
      {
        cout << p;
      }
  }

void find_and_replace (Document &document, const string &from, const string &to)
  {
    for (auto &iter : document.line)
      {
        // create a temp line as a string.
        string line;
        for (auto c : iter)
          {
            line.push_back(c);
          }
        
        // check if the line contains "from".
        auto index = line.find(from);
        
        // replace if it does.
        if (index != string::npos)
          {
            line.replace(index, from.length(), to);
          }
        
        // change the size of the iter to the line size and copy the temp line to the iter.
        // the resize is needed to deal with '\n'.
        iter.resize(line.size());
        copy(line.begin(), line.end(), iter.begin());
      }
  }

size_t count_number_of_character (Document &document)
  {
    size_t count { 0 };
    
    for (const auto &item : document)
      {
        count++;
      }
    return count;
  }

int main (int argc, char *argv[])
try
  {
    Document document;
    
    istringstream iss { "Some line with text\nline two\nanother line\none more!!!\n" };
    
    iss >> document;
    
    print(document);
    
    cout << count_number_of_character(document) << endl;
    
    find_and_replace(document, "line", "XXX");
    
    print_line_break();
    
    print(document);
    
    cout << count_number_of_character(document) << endl;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

