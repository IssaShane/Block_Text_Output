#include "word_engine.h"

using namespace std;

// word_engine loads the file letters.csv
word_engine::word_engine() {
  //cout << "constructor" << endl;
  file.load("letters.csv");
}

// char_to_int (c) gives the position in the alphabet of the capital letter c
// effects: none
// efficiency: O(1)
// requirements: c is a capital letter
int char_to_int (char c) {
  int x = c;
  x -= 65;
  return x;
}

// find_x_coord (pos) gives the appropriate x coordinate on the grid of letters.csv
//   for the upper left corner of the posth letter of the alphabet
// effects: none
// efficiency: O(1)
// requirements: 0 <= pos <= 26
int find_x_coord(int pos) {
  int x = pos*4;
  if (pos <= 8) return x;
  else if (pos <= 16) return (x - 8*4);
  else return (x - 16*4);
}

// find_y_coord (pos) gives the appropriate y coordinate on the grid of letters.csv
//   for the upper left corner of the posth letter of the alphabet
// effects: none
// efficiency: O(1)
// requirements: 0 <= pos <= 26
int find_y_coord(int pos) {
  if (pos <= 8) return 0;
  else if (pos <= 16) return 1;
  else return 2;
}

// printLetter(c, word) prints the letter c composed of the word word to standard
//   output
// effects: output
// efficiency: O(n³) [very bad]
// requirements: c is a capital letter
void word_engine::printLetter(char c, string word) {
  //cout << "print letter" << endl;
  int x = char_to_int(c); // position in the alphabet
  int start_x = find_x_coord(x);
  int start_y = find_y_coord(x);

  //cout << "x: " << start_x << endl << "y: " << start_y << endl << "pos: " << x << endl;

  for (int i = start_y; i < 5; i++) {
    //cout << "row" << endl;
    for (int j = start_x; j < 4; j++) {
      //cout << "columns" << endl;
      if (file.getElement(j, i) == 1) {
        //cout << "hi";
        std::cout << word;
      }
      else if (file.getElement(j, i) == 0) {
        //cout << "jk";
        int len = word.length();
        for (int t = 0; t < len; t++) cout << " ";
      }
      else cout << file.getElement(j, i);
    }
    cout << endl;
  }
}
