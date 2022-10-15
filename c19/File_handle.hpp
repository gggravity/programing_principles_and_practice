//
// Created by martin on 15-10-22.
//

#pragma once

#include <bits/stdc++.h>

#include <utility>

using namespace std;

class File_handle
  {
  public:
    explicit File_handle (const string &filename) : filename(filename)
      {
        fh = fopen(filename.c_str(), "r");
        
        if (!fh)
          {
            fprintf(stderr, "Error opening file '%s'\n", filename.c_str());
            exit(EXIT_FAILURE);
          }
        else
          {
            fprintf(stdout, "opening file '%s'\n", filename.c_str());
          }
      }
    
    virtual ~File_handle ()
      {
        fclose(fh);
        fprintf(stdout, "closing file '%s'\n", filename.c_str());
      }
    
    [[nodiscard]] FILE *get () const
      {
        return fh;
      }
  
  private:
    string filename;
    FILE *fh;
  };