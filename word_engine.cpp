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
// requirements: 0 <= pos <= 25
int find_x_coord(int pos) {
  int x = pos*4;
  if (pos <= 8) return x;
  else if (pos <= 17) return (x - 9*4);
  else return (x - 18*4);
}

// find_y_coord (pos) gives the appropriate y coordinate on the grid of letters.csv
//   for the upper left corner of the posth letter of the alphabet
// effects: none
// efficiency: O(1)
// requirements: 0 <= pos <= 25
int find_y_coord(int pos) {
  if (pos <= 8) return 0;
  else if (pos <= 17) return 5;
  else return 10;
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

  for (int i = start_y; i < 5+start_y; i++) {
    //cout << "row" << endl;
    for (int j = start_x; j < 4+start_x; j++) {
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

char capitalize(char c) {
  if (c>90) return c - 32;
  else return c;
}

void word_engine::printLetterLine(char c, int n, string word) {
  int pos = char_to_int(c);
  int start_x = find_x_coord(pos);
  int start_y = find_y_coord(pos);
  start_y += n; // locate the correct line of the letter

  //cout << "x: " << start_x << endl << "y: " << start_y << endl << "pos: " << pos << endl;

  for (int j = start_x; j < 4 + start_x; j++) {
    //cout << "columns" << endl;
    if (file.getElement(j, start_y) == 1) {
      //cout << "hi";
      std::cout << word;
    }
    else if (file.getElement(j, start_y) == 0) {
      //cout << "jk";
      int len = word.length();
      for (int t = 0; t < len; t++) cout << " ";
    }
    else cout << file.getElement(j, start_y);
  }
}

void word_engine::printString(string word) {
  int len = word.length();

  for (int i = 0; i < 5; i++) {
    for (int t = 0; t < len; t++) {
      printLetterLine(capitalize(word[t]), i, word);
      cout << " ";
    }
    cout << endl;
  }
}
