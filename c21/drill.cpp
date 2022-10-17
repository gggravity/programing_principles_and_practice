#include "../std_lib.h"

using namespace std;

#define FILENAME "../c21/drill.txt"
#define MAP_FILENAME "../c21/drill_map.txt"
#define VECTOR_FILENAME "../c21/drill_float.txt"

struct Item
    {
        Item () = default;
        
        Item (string name, int iid, double value) :
            name(std::move(name)),
            iid(iid),
            value(value)
          { }
        
        string name;
        int iid { };
        double value { };
        
        friend ostream &operator<< (ostream &os, const Item &item)
          {
            os << item.name << " " << item.iid << " " << item.value;
            return os;
          }
        
        friend istream &operator>> (istream &is, Item &item)
          {
            is >> item.name >> item.iid >> item.value;
            return is;
          }
    };

vector<string> split (const string &text, char delimiter = ' ')
  {
    vector<string> words { };
    
    istringstream iss { text };
    string s;
    while (getline(iss, s, delimiter))
      {
        words.push_back(s);
      }
    
    return words;
  }

template < typename Container >
auto fill_from_file (Container &container)
  {
    ifstream ifs { FILENAME };
    if (!ifs)
      {
        cerr << "File not found: " << FILENAME << endl;
        exit(EXIT_FAILURE);
      }
    
    string line;
    while (!ifs.eof())
      {
        getline(ifs, line);
        Item item;
        istringstream iss { line };
        iss >> item;
        container.push_back(item);
      }
    return container;
  }

template <>
auto fill_from_file (map<string, int> &container)
  {
    ifstream ifs { MAP_FILENAME };
    if (!ifs)
      {
        cerr << "File not found: " << MAP_FILENAME << endl;
        exit(EXIT_FAILURE);
      }
    
    string line;
    while (!ifs.eof())
      {
        getline(ifs, line);
        auto s = split(line);
        container[s[0]] = stoi(s[1]);
      }
    return container;
  }

auto fill_from_file (vector<double> &vec)
  {
    ifstream ifs { VECTOR_FILENAME };
    if (!ifs)
      {
        cerr << "File not found: " << VECTOR_FILENAME << endl;
        exit(EXIT_FAILURE);
      }
    
    string line;
    while (!ifs.eof())
      {
        getline(ifs, line);
        vec.push_back(stod(line));
      }
    return vec;
  }

int map_sum (map<string, int> &msi)
  {
    int counter { 0 };
    
    for (auto [key, value] : msi)
      {
        counter += value;
      }
    return counter;
  }

bool sort_by_name (const Item &a, const Item &b)
  {
    return a.name < b.name;
  }

bool sort_by_id (const Item &a, const Item &b)
  {
    return a.iid < b.iid;
  }

bool sort_by_value (const Item &a, const Item &b)
  {
    return a.value > b.value;
  }

template < typename Container >
void erase_name (Container &container, const string &to_remove)
  {
    container.erase(remove_if(container.begin(), container.end(), [&] (const Item &item)
      {
          return item.name == to_remove;
      }), container.end());
  }

template < typename Container >
void erase_id (Container &container, int to_remove)
  {
    container.erase(remove_if(container.begin(), container.end(), [&] (const Item &item)
      {
          return item.iid == to_remove;
      }), container.end());
  }

void run_exercises (vector<Item> &container)
  {
    print(container);
    
    sort(container, sort_by_name);
    
    print(container);
    
    sort(container, sort_by_id);
    
    print(container);
    
    sort(container, sort_by_value);
    
    print(container);
    
    container.push_back(Item("horse shoe", 99, 12.34));
    container.push_back(Item("Canon S400", 9988, 499.95));
    
    print(container);
    
    erase_name(container, "Anna");
    
    erase_name(container, "horse shoe");
    
    print(container);
    
    erase_id(container, 7);
    
    erase_id(container, 9);
    
    print(container);
  }

void run_exercises (list<Item> &container)
  {
    print(container);
    
    container.sort(sort_by_name);
    
    print(container);
    
    container.sort(sort_by_id);
    
    print(container);
    
    container.sort(sort_by_value);
    
    print(container);
    
    container.emplace_back("horse shoe", 99, 12.34);
    container.emplace_back("Canon S400", 9988, 499.95);
    
    print(container);
    
    erase_name(container, "Anna");
    
    erase_name(container, "horse shoe");
    
    print(container);
    
    erase_id(container, 7);
    
    erase_id(container, 9);
    
    print(container);
  }

map<string, int> insert_into_map (map<string, int> &msi)
  {
    msi["lecture"] = 21;
    msi["class"] = 11;
    msi["struct"] = 1;
    msi["string"] = 3;
    msi["speech"] = 2;
    msi["room"] = 12;
    msi["school"] = 15;
    msi["job"] = 44;
    msi["computer"] = 4;
    msi["music"] = 19;
    
    return msi;
  }

template < typename T, typename U >
void print (map<T, U> &m)
  {
    if (m.empty())
      {
        cout << "The map is empty." << endl;
        return;
      }
    
    for (auto [key, value] : m)
      {
        cout << key << " -> " << value << endl;
      }
  }

void msi_to_mis (const map<string, int> &msi, map<int, string> &mis)
  {
    if (!mis.empty())
      {
        cout << "The int string map is not empty." << endl;
        return;
      }
    
    for (auto [key, value] : msi)
      {
        mis[value] = key;
      }
  }

int main (int argc, char *argv[])
  {
    vector<Item> vi;
    vi = fill_from_file(vi);

    run_exercises(vi);

    print_line_break();

    list<Item> li;
    li = fill_from_file(li);

    run_exercises(li);

    print_line_break();
    
    map<string, int> msi;

    msi = insert_into_map(msi);

    print(msi);

    msi.clear();

    print(msi);
    
    msi = fill_from_file(msi);
    
    print(msi);
    
    cout << "map_sum: " << map_sum(msi) << endl;
    
    map<int, string> mis;
    
    msi_to_mis(msi, mis);
    
    print_line_break();
    
    print(mis);
    
    vector<double> vd;
    
    fill_from_file(vd);
    
    print(vd);
    
    vector<int> vint(vd.size());
    
    copy(vd, vint);
    
    for (size_t i { 0 } ; i < vint.size() ; ++i)
      {
        cout << vd[i] << " -> " << vint[i] << endl;
      }
    
    auto sum_vd { accumulate(vd.begin(), vd.end(), double(0)) };
    auto sum_vint { accumulate(vint.begin(), vint.end(), int(0)) };
    cout << "sum of vd: " << sum_vd << endl;
    cout << "sum of vi: " << sum_vint << endl;
    cout << "sum of diff: " << abs(sum_vint - sum_vd) << endl;
    
    print(vd);
    reverse(vd.begin(), vd.end());
    print(vd);
    auto mean_vd { sum_vd / double(vd.size()) };
    
    cout << "mean_vd: " << mean_vd << endl;
    
    vector<double> vd2;
    
    copy_if(vd.begin(), vd.end(), back_inserter(vd2),
            [mean_vd] (double d)
              {
                  return d < mean_vd;
              });
    
    sort(vd);
    sort(vd2);
    
    print(vd);
    print(vd2);
    
    return EXIT_SUCCESS;
  }
