#include <bits/stdc++.h>

using namespace std;

void print_c (const string &msg, const int ia[], size_t n)
  {
    cout << msg << ": ";
    for (auto iter { 0 } ; iter < n ; ++iter)
      {
        cout << ia[iter] << " ";
      }
    cout << endl;
  }

template < typename T >
void print (const string &msg, T t)
  {
    cout << msg << ": ";
    for (const auto i : t)
      {
        cout << i << " ";
      }
    cout << endl;
  }

template < typename Iter1, typename Iter2 >
void multiply (Iter1 begin, Iter2 end, int n)
  {
    for (auto iter = begin ; iter != end ; ++iter)
      {
        *iter *= n;
      }
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

template < typename Container, typename N>
void find_n (Container container, N n)
  {
    auto iter = find(container.begin(), container.end(), n);
    if (iter != container.end())
      {
        cout << "found " << n << " at position " << distance(container.begin(), iter) << endl;
      }
    else
      {
        cout << n << " not found" << endl;
      }
  }

int main (int argc, char *argv[])
try
  {
    array<int, 10> ai10 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    int ai[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    print("ai10", ai10);
    
    print_c("ai", ai, 10); // not working
    
    vector<int> vi { ai10.begin(), ai10.end() };
    
    print("vi", vi);
    
    list<int> li { vi.begin(), vi.end() };
    
    print("li", li);
    
    auto ai102 = ai10;
    auto vi2 = vi;
    auto li2 = li;
    
    int ai2[10];
    std::copy(begin(ai), end(ai), begin(ai2));
    
    print_c("ai2", ai2, 10);
    
    print("ai102", ai102);
    print("vi2", vi2);
    print("li2", li2);
    
    cout << "-----------------" << endl;
    
    multiply(ai102.begin(), ai102.end(), 2);
    multiply(vi2.begin(), vi2.end(), 2);
    multiply(li2.begin(), li2.end(), 2);
    multiply(begin(ai2), end(ai2), 2);
    
    print("ai102", ai102);
    print("vi2", vi2);
    print("li2", li2);
    print_c("ai2", ai2, 10);
    
    cout << "-----------------" << endl;
    
    multiply(ai102.begin(), ai102.end(), 3);
    multiply(vi2.begin(), vi2.end(), 3);
    multiply(li2.begin(), li2.end(), 3);
    multiply(begin(ai2), end(ai2), 3);
    
    print("ai102", ai102);
    print("vi2", vi2);
    print("li2", li2);
    print_c("ai2", ai2, 10);
    
    cout << "-----------------" << endl;
    
    multiply(ai102.begin(), ai102.end(), 5);
    multiply(vi2.begin(), vi2.end(), 5);
    multiply(li2.begin(), li2.end(), 5);
    multiply(begin(ai2), end(ai2), 5);
    
    print("ai102", ai102);
    print("vi2", vi2);
    print("li2", li2);
    print_c("ai2", ai2, 10);
    
    cout << "-----------------" << endl;
    vector<int> vi_copy(vi.size());
    Copy(vi.begin(), vi.end(), vi_copy.begin());
    
    print("vi", vi);
    print("vi_copy", vi_copy);
    
    vector<int> vi_from_array(10);
    
    Copy(ai10.begin(), ai10.end(), vi_from_array.begin());
    
    print("vi_from_array", vi_from_array);
    
    li.clear();
    li.resize(10);
    print("li", li);
    Copy(vi_from_array.begin(), vi_from_array.end(), li.begin());
    print("li", li);
    
    find_n(vi, 3);
    
    find_n(li, 27);
    
    find_n(li2, 150);
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

