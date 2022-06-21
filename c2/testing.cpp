//
// Created by martin on 20/01/2022.
//

#include "testing.h"

int testing::get_counter () const
  {
	return m_counter;
  }

void testing::set_counter (int counter)
  {
	testing::m_counter = counter;
  }
