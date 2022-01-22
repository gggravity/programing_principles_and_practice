#include "../std_lib_facilities.h"

class Name_value
{
  public:
	  string name;
	  int score {0};
};

ostream &operator<< (ostream &os, const Name_value &nv)
{
  return os << nv.name << "\t\t" << nv.score;
}

istream &operator>> (istream &is, Name_value &nv)
{
  is >> nv.name;
  is >> nv.score;
  return is;
}

bool operator== (const Name_value &lhs, const Name_value &rhs)
{
  return lhs.name == rhs.name;
}

int main ()
{

  vector<Name_value> v;

  cout << "Enter a name value pair like Joe 14, end input with nn 0:" << endl;

  Name_value name_value;

  while (cin >> name_value)
  {
	if (name_value.name == "nn" && name_value.score == 0)
	{
	  break;
	}
	if (v.empty())
	{
	  v.push_back(name_value);
	}
	else
	{
	  auto pred = [name_value] (const Name_value &item)
	  {
		  return item == name_value;
	  };

	  auto it = find_if(v.begin(), v.end(), pred);
	  if (it == v.end())
	  {
		v.push_back(name_value);
	  }
	  else
	  {
		cerr << "Duplicated name error." << endl;
	  }
	}
  }

  cout << "Name\t\tScore\n";
  for (const auto &nv: v)
  {
	cout << nv << endl;
  }

}