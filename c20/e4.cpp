//
// Created by martin on 15-10-22.
//

#include <bits/stdc++.h>

using namespace std;

double high (const vector<double> &data)
  {
    return *max_element(data.begin(), data.end());
  }

double high (const double arr[], int n)
  {
    return *max_element(&arr[0], &arr[n]);
  }

int main (int argc, char *argv[])
try
  {
    
    auto jill_data = new vector<double> { 123.1, 123.4, 213.9, 321.4, 423.0, 543.0, 324.4, 123.6 };
    double jack_data[] = { 123.2, 123.5, 213.3, 321.4, 666.6, 543.9, 324.0, 123.4 };
    
    auto jack_high = high(jack_data, 8);
    auto jill_high = high(*jill_data);
    
    cout << "Jill's max: " << jill_high
         << "; Jack's max: " << jack_high;
    
    delete jill_data;
    
    return EXIT_SUCCESS;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }

