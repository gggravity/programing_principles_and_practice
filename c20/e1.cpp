//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>

using namespace std;

template < typename Container >
auto find_max (Container container)
  {
    auto iter = container->begin();
    for (auto const &item : *container)
      {
        if (item > *iter)
          {
            *iter = item;
          }
      }
    return iter;
  }

template < typename Iter1, typename Iter2 >
Iter2 Copy (Iter1 f1, Iter1 e1, Iter2 f2)
  {
    if (f1 == e1)
      {
        return f2;
      }
    for (auto iter = f1 ; iter < e1 ; ++iter, ++f2)
      {
        *f2 = *iter;
      }
    return f2;
  }

template < typename Container >
void print (Container container)
  {
    cout << "{ ";
    for (auto iter { container.begin() } ; iter != container.end() ; ++iter)
      {
        if (iter != container.end() - 1)
          {
            cout << *iter << ", ";
          }
        else
          {
            cout << *iter;
          }
      }
    cout << " }" << endl;
  }

template < typename T >
struct Vector : vector<T>
    {
        using size_type = typename vector<T>::size_type;
        
        using vector<T>::vector;    // inheriting constructor
        
        void push_front (T t)
          {
            this->insert(this->begin(), t);
          }
    };

template < typename Iter >
void Advance (Iter &p, int n)
  {
    if (n >= 0)
      {
        while (0 < n)
          {
            ++p;
            --n;
          }
      }
    else
      {
        while (n < 0)
          {
            --p;
            ++n;
          }
      }
  }

template < typename Container >
void string_function (Container container)
  {
    cout << container.size() << endl;
    
    string s { };
    
    for (const auto &c : container)
      {
        s.push_back(c);
      }
    cout << boolalpha << ( s == "Hello" ) << endl;
    
    cout << "Howdy test: " << (s < "Howdy") << endl;
  }

template < typename Container >
void int_function (Container container)
  {
    cout << container.size() << endl;
    
    bool is_same = true;
    int number = 1;
    
    for (const auto &item : container)
      {
        if (item != number)
          {
            is_same = false;
          }
        number++;
      }
    
    cout << boolalpha << is_same << endl;
  }

int main (int argc, char *argv[])
try
  {
    auto jill_date = new vector<double>({ -123.12, -321.21, -22.33, -32.00 });

//    double h = -1;
    double h = numeric_limits<double>::lowest();
    double *jill_high;
    
    for (int i = 0 ; i < jill_date->size() ; ++i)
      {
        if (h < ( *jill_date )[i])
          {
            jill_high = &( *jill_date )[i];
            h = ( *jill_date )[i];
          }
      }
    
    cout << *jill_high << endl;
    
    // Don't work for numbers below -1
    
    cout << *find_max(jill_date) << endl;
    
    print(*jill_date);
    
    auto jill_date_copy = new vector<double>(jill_date->size());
    
    print(*jill_date_copy);
    
    Copy(jill_date->begin(), jill_date->end(), jill_date_copy->begin());
    
    print(*jill_date_copy);
    
    delete jill_date;
    delete jill_date_copy;
    
    Vector<string> vs { "A", "B", "C" };
    
    vs.push_back("D");
//    vs.resize(vs.size() + 1);
    
    
    print(vs);
    
    vs.push_front("HALLO");
    
    print(vs);
    
    auto iter = vs.begin();
    Advance(iter, 2);
    cout << *iter << endl;
    
    Advance(iter, -2);
    cout << *iter << endl;
    
    array<char, 5> ac { 'H', 'e', 'l', 'l', 'o' };
    vector<char> vc { 'H', 'e', 'l', 'l', 'o' };
    list<char> lc { 'H', 'e', 'l', 'l', 'o' };
    string hello_str { "Hello" };
    
    string_function(ac);
    string_function(vc);
    string_function(lc);
    string_function(hello_str);
    
    cout << "-----------" << endl;
    
    array<int, 5> ai { 1, 2, 3, 4, 5 };
    vector<int> vi { 1, 2, 3, 4, 5 };
    list<int> li { 1, 2, 3, 4, 5 };
    
    int_function(ai);
    int_function(vi);
    int_function(li);
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

