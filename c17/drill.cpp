#include <bits/stdc++.h>

using namespace std;

void print_array10 (ostream &os, int *a)
  {
    for (int i = 0 ; i < 10 ; i++)
      {
        if (i != 9)
          {
            os << a[i] << ", ";
          }
        else
          {
            os << a[i] << "." << endl;
          }
      }
  }

void print_array (ostream &os, int *a, int n)
  {
    for (int i = 0 ; i < n ; i++)
      {
        if (i != n - 1)
          {
            os << a[i] << ", ";
          }
        else
          {
            os << a[i] << "." << endl;
          }
      }
  }

void print_vector (ostream &os, vector<int> v)
  {
    for (int i = 0 ; i < v.size() ; i++)
      {
        if (i != v.size() - 1)
          {
            os << v[i] << ", ";
          }
        else
          {
            os << v[i] << "." << endl;
          }
      }
  }

int main (int argc, char *argv[])
  {
    int *array1 = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0 ; i < 10 ; i++)
      {
        if (i != 9)
          {
            cout << array1[i] << ", ";
          }
        else
          {
            cout << array1[i] << "." << endl;
          }
      }

    int *array2 = new int[] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };

    print_array10(cout, array2);

    int *array3 = new int[] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };

    print_array(cout, array3, 11);

    int *array4 = new int[] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117,
                              118, 120 };

    print_array(cout, array4, 20);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;

    vector<int> vector1 { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
    vector<int> vector2 { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
    vector<int> vector3 { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117,
                          118, 120 };

    print_vector(cout, vector1);
    print_vector(cout, vector2);
    print_vector(cout, vector3);

  }
