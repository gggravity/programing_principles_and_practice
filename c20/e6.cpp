//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>

using namespace std;

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

int main (int argc, char *argv[])
try
  {
    Document document;
    
    istringstream iss { "Some line with text\nline two\nanother line\none more!!!" };
    
    iss >> document;
    
    print(document);
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

