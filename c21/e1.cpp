#include "../std_lib.h"

using namespace std;

template < typename ln, typename T >
ln find1 (ln first, ln last, const T &val)
  {
    while (first != last && *first != val)
      {
        ++first;
      }
    return first;
  }

template < typename ln, typename T >
ln find2 (ln first, ln last, const T &val)
  {
    for (ln p = first ; p != last ; ++p)
      {
        if (*p == val)
          {
            return p;
          }
      }
    return last;
  }

struct Record
    {
        double unit_price;
        int units;
    };

double price (double v, const Record &r)
  {
    return v + r.unit_price * r.units;
  }

double weighted_value (const pair<string, double> &a, const pair<string, double> &b)
  {
    return a.second * b.second;
  }

int main (int argc, char *argv[])
  {
    header("VECTOR INT", true);
    vector<int> vi { 0, 1, 2, 3, 4, 5, 6, 7, 8, 5, 7, 8, 4, 2, 4, 7, 8, 9, 1 };
    
    cout << *find1(vi.begin(), vi.end(), 7) << endl;
    
    cout << *find2(vi.begin(), vi.end(), 7) << endl;
    
    header("RECORD");
    
    vector<Record> vr {
        { 12.99,  10 },
        { 29.98,  6 },
        { 99.98,  100 },
        { 12.99,  10 },
        { 129.49, 3 },
        { 22.50,  20 }
    };
    
    auto sum { accumulate(vr.begin(), vr.end(), 0.0, price) };
    
    cout << "sum: " << sum << endl;
    
    header("DOW JONES INDEX");
    
    map<string, double> dow_price {
        { "MMM", 81.86 },
        { "AA",  34.69 },
        { "MO",  54.45 }
    };
    
    map<string, double> dow_weight {
        { "MMM", 5.8549 },
        { "AA",  2.4808 },
        { "MO",  3.8940 }
    };
    
    map<string, string> dow_name {
        { "MMM", "3M Co." },
        { "AA",  "Alcoa Inc." },
        { "MO",  "Altria Group Inc." }
    };
    
    if (dow_price.find("INTC") != dow_price.end())
      {
        cout << "Intel is in the Dow" << endl;
      }
    
    if (dow_price.find("MMM") != dow_price.end())
      {
        cout << "MMM is in the Dow" << endl;
      }
    
    for (const auto &p : dow_price)
      {
        const string &symbol { p.first };
        cout << symbol << "\t" << p.second << "\t" << dow_name[symbol] << endl;
      }
    
    double dji_index {
        inner_product(dow_price.begin(),
                      dow_price.end(),
                      dow_weight.begin(),
                      0.0,
                      plus<double>(),
                      weighted_value)
    };
    
    cout << "dji_index: " << "\t" << dji_index << endl;
    
    header("NAME AGE MAP");
    
    unordered_map<string, int> age_map {
        { "Anna",  23 },
        { "Brian", 32 },
        { "Adam",  24 },
        { "Bob",   25 },
        { "Lisa",  29 }
    };
    
    for (auto [name, age] : age_map)
      {
        cout << setw(12) << left << name << age << endl;
      }
    
    return EXIT_SUCCESS;
  }
