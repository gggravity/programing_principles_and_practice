#include "../std_lib_facilities.h"

int main ()
{
  vector<string> words = {
	  "paint",
	  "chair",
	  "talented",
	  "integrity",
	  "name",
	  "pace",
	  "thought",
	  "civilization",
	  "deep",
	  "stain",
	  "solid",
	  "visual",
  };

  vector<string> v;

  for (int i = 0 ; i <= 100 ; ++i)
  {
	v.push_back(words[rand() % words.size() ]);
  }

  string min_string = *min_element(v.begin(), v.end());
  string max_string = *max_element(v.begin(), v.end());

  vector<int> frequency(words.size());

  for (const auto& word: v)
  {
	auto it = find(words.begin(), words.end(), word);
	auto index = distance(words.begin(),it);
	frequency[index]++;
  }

  for (int i = 0; i != words.size(); ++i)
  {
	cout << frequency[i] << "\t\t" << words[i] << endl;
  }

  int max_freq = *max_element(frequency.begin(), frequency.end());

  string mode;
  for (int i = 0 ; i < frequency.size() ; ++i)
  {
	if (frequency[i] == max_freq)
	{
	  mode = words[i];
	}
  }

  cout << endl;
  cout << "Min:" << "\t\t" << min_string << endl;
  cout << "Max:" << "\t\t" << max_string << endl;
  cout << "Mode:" << "\t\t" << mode;

}
