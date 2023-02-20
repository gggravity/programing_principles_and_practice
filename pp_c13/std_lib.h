//
// Created by martin on 18/01/2022.
//

#ifndef _STD_LIB_H_
#define _STD_LIB_H_

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <forward_list>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <list>
#include <ostream>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>


// random number generators. See 24.7.

inline std::default_random_engine &get_rand ()
  {
	static std::default_random_engine ran;    // note: not thread_local
	return ran;
  }

inline void seed_randint (int s)
  {
	get_rand().seed(s);
  }

inline int randint (int min, int max)
  {
	return std::uniform_int_distribution<> {min, max}(get_rand());
  }

inline int randint (int max)
  {
	return randint(0, max);
  }

#endif //_STD_LIB_H_
