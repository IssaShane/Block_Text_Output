#include <iostream>
#include <string>
#include <fstream>
#include "csv.h"
#include "word_engine.h"

using namespace std;

int main () {
  word_engine output;
  string word;

  cout << "please enter a word: ";
  cin >> word;
  output.printString(word);

  return 0;
}
