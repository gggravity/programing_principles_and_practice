//
// Created by martin on 10/22/22.
//

#include "../std_lib.h"

typedef vector<string>::const_iterator Line_iter;

class Message
  {
  public:
    Message (const Line_iter &first, const Line_iter &last) :
        first(first),
        last(last)
      {
        
      }
    
    [[nodiscard]] Line_iter begin () const
      {
        return first;
      }
    
    [[nodiscard]] Line_iter end () const
      {
        return last;
      }
  
  private:
    Line_iter first;
    Line_iter last;
  };

using Message_iter = vector<Message>::const_iterator;

struct Mail_file
    {
        string name;
        vector<string> lines;
        vector<Message> messages;
        
        explicit Mail_file (const string &filename)
          {
            ifstream ifs { filename };
            if (!ifs)
              {
                cerr << "no " << filename << endl;
                exit(EXIT_FAILURE);
              }
            
            for (string line ; getline(ifs, line) ; /* */)
              {
                lines.push_back(line);
              }
            
            regex separator { R"(^----$)" };
            smatch matches;
            
            auto first = lines.begin();
            for (auto p { lines.begin() } ; p != lines.end() ; ++p)
              {
                if (regex_search(*p, matches, separator))
                  {
                    messages.push_back(Message(first, p));
                    first = p + 1;
                  }
              }
          }
        
        [[nodiscard]] Message_iter begin () const
          {
            return messages.begin();
          }
        
        [[nodiscard]] Message_iter end () const
          {
            return messages.end();
          }
    };

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

bool find_from_address (const Message *message, string &str)
  {
    for (const auto &line : *message)
      {
        if (auto n { is_prefix(line, "From: ") })
          {
            str = string(line, n);
            return true;
          }
      }
    return false;
  }

string find_subject (const Message *message)
  {
    for (const auto &x : *message)
      {
        if (auto n { is_prefix(x, "Subject: ") })
          {
            return string(x, n);
          }
      }
    return "";
  }

int main (int argc, char *argv[])
  {
    Mail_file mail_file { "../c23/sample.mbox" };

//    multimap<string, const Message *> sender;
//
//    for (const auto &message : mail_file)
//      {
//        string str;
//        if (find_from_address(&message, str))
//          {
//            sender.insert(make_pair(str, &message));
//          }
//      }
    /*
    auto pp = sender.equal_range("Neil Pickford <neilp@goldweb.com.au>");
    
    for (auto p { pp.first } ; p != pp.second ; ++p)
      {
        cout << find_subject(p->second) << endl;
      }
      */
    
    using Subject = string;
    
    multimap<Subject, const Message *> subjects;
    
    for (const auto &message : mail_file)
      {
        auto subject = find_subject(&message);
        subjects.insert(make_pair(subject, &message));
      }
    
    istringstream iss { "Report" };
    
    for (auto [subject, message] : subjects)
      {
        auto found = subject.find(iss.str());
        if (found != string::npos)
          {
            cout << subject << " -> " << message << endl;
          }
      }
    
    return EXIT_SUCCESS;
  }
