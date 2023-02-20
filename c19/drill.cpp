#include <bits/stdc++.h>
#include <ostream>

using namespace std;

template < typename T >
struct S
  {
    S ()
      {
      
      }
    
    S (T val) : m_val { val }
      {
      
      }
    
    friend ostream &operator<< (ostream &os, const S &s)
      {
        os << "val: " << s.m_val;
        return os;
      };
    
    friend istream &operator>> (istream &is, vector<T> &v)
      {
        string input;
        
        is.ignore(INT_MAX, '\n');
        getline(cin, input);
        stringstream ss(input);
        
        T val;
        while (ss >> val)
          {
            v.push_back(val);
          }
        
        return is;
      }

//    friend istream &operator>> (istream &is, S<T> &s)
//      {
//        T v;
//        cin >> v;
//        if (!is)
//          {
//            return is;
//          }
//        s = v;
//        return is;
//      };

//    friend istream &operator>> (istream &is, vector<T> &v)
//      {
//        string input;
//        getline(is, input);
//
//        stringstream ss(input);
//
//        T val;
//        while (ss >> val)
//          {
//            v.push_back(val);
//          }
//
//        return is;
//      }
    
    
    T &operator= (const T &rhs);
    
    T &operator[] (int index)
      {
        return m_val;
      }
    
    const T &operator[] (int index) const
      {
        return m_val;
      }
    
    T &get ();
    
    const T &get () const;
    
    void set (T val);
  
  private:
    T m_val;
  };

template < typename T >
void read_val (vector<T> &v)
  {
    cin >> v;
  }



template < typename T >
T &S<T>::operator= (const T &rhs)
  {
    m_val = rhs;
    return get();
  }

template < typename T >
T &S<T>::get ()
  {
    return m_val;
  }

template < typename T >
const T &S<T>::get () const
  {
    return m_val;
  }

template < typename T >
void S<T>::set (T val)
  {
    m_val = val;
  }

int main (int argc, char *argv[])
try
  {
/*
    S<int> s_int { 123 };
    S<char> s_char { 'X' };
    S<double> s_double { 123.123 };
    S<string> s_string { "Hello world !!!" };

    vector<int> vi { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    S<vector<int>> s_vector_int { vi };

    cout << s_int << endl;
    cout << s_char << endl;
    cout << s_double << endl;
    cout << s_string << endl;

    cout << "--------------" << endl;

    for (auto &v : s_vector_int.get())
      {
        cout << v << " ";
      }

    cout << endl << "--------------" << endl;

    cout << s_int.get() << endl;
    cout << s_char.get() << endl;
    cout << s_double.get() << endl;
    cout << s_string.get() << endl;

    for (auto &v : s_vector_int.get())
      {
        cout << v << " ";
      }
    cout << endl;

    cout << "--------------" << endl;

    s_int.set(321);
    s_char.set(( 'y' ));
    s_double.set(321.321);
    s_string.set("World C++");
    s_vector_int.set({ 9, 8, 7, 6, 5, 4, 3, 2, 1 });

    cout << s_int << endl;
    cout << s_char << endl;
    cout << s_double << endl;
    cout << s_string << endl;
    for (auto &v : s_vector_int.get())
      {
        cout << v << " ";
      }
    cout << endl;

    cout << "--------------" << endl;

    s_int = 111;
    s_char = 'Z';
    s_double = 333.333;
    s_string = "C++ Rocks";
    s_vector_int = { 4, 4, 4, 3, 3, 3 };

    cout << s_int << endl;
    cout << s_char << endl;
    cout << s_double << endl;
    cout << s_string << endl;
    for (auto &v : s_vector_int.get())
      {
        cout << v << " ";
      }
    cout << endl;

    cout << "--------------" << endl;
*/
    
    S<std::vector<int>> s5;
    read_val(s5);
//    std::cout << s5 << '\n';


//    S<int> read_val_int;
//
//    read_val(read_val_int);
//
//    cout << read_val_int;

//    cout << "input an int: " << endl;
//    read_val(s_int);
//    cout << s_int << endl;
//
//    cout << "input an char: " << endl;
//    read_val(s_char);
//    cout << s_char << endl;
//
//    cout << "input an double: " << endl;
//    read_val(s_double);
//    cout << s_double << endl;
//
//    cout << "input an string (no spaces): " << endl;
//    read_val(s_string);
//    cout << s_string << endl;
    
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }

