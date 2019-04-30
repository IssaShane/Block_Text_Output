#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include <iostream>
#include <string>
#include "csv.h"

using namespace std;

class word_engine {
  public:
    word_engine();
    void printLetter(char c, string word);

  private:
    CSV file;

};

#endif
