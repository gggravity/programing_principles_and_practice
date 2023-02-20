//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>

using namespace std;

double *high (double *first, double *last)
  {
    double_t h = -1;
    double *high;
    
    for (double *p = first ; p != last ; ++p)
      {
        if (h < *p)
          {
            high = p;
            h = *p;
          }
      }
    return high;
  }

int main (int argc, char *argv[])
try
  {
    
    auto jill_data = new vector<double> { 123.1, 123.4, 213.9, 321.4, 423.0, 543.0, 324.4, 123.6 };
    double jack_data[] = { 123.2, 123.5, 213.3, 321.4, 666.6, 543.9, 324.0, 123.4 };
    
    int jack_count = 8;
    
    double *jack_high = high(&jack_data[0], &jack_data[0] + jack_count);
    vector<double> &v = *jill_data;
    double *jill_high = high(&v[0], &v[0] + v.size());
    
    cout << "Jill's max: " << *jill_high
         << "; Jack's max: " << *jack_high;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

