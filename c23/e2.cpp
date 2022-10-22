//
// Created by martin on 10/21/22.
//

#include "../std_lib.h"

template < typename T >
string to_string (const T &t)
  {
    ostringstream oss;
    oss << t;
    return oss.str();
  }

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
            
            auto first = lines.begin();
            for (auto p { lines.begin() } ; p != lines.end() ; ++p)
              {
                if (*p == "----")
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
    auto n { int(prefix.size()) };
    if (string(line, 0, n) == prefix)
      {
        return n;
      }
    return 0;
  }

bool find_from_address (const Message *message, string &str)
  {
    for (const auto &x : *message)
      {
        if (auto n { is_prefix(x, "From: ") })
          {
            str = string(x, n);
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
/*
    auto test1 { from_string<int>("123") };
    auto test2 { to_string<double>(123.123) };
    cout << test1 << endl;
    cout << test2 << endl;
*/
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
