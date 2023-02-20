//
// Created by martin on 15-10-22.
//

#pragma once

#include <bits/stdc++.h>
#include "terminal_colors.h"

using namespace std;
using namespace terminal_colors;

struct Tracer
    {
        explicit Tracer (const string &message) : message(message)
          {
            cout << green("START: ") << message << endl;
          }
        
        virtual ~Tracer ()
          {
            cout << red("STOP: ") << message << endl;
          }
        
        string message;
    };