#include "csv.h"

using namespace std;

CSV::CSV() {}

// CSV(filename) loads the file loacated at filename, and inputs them into a
//   2 dimensional vector
// effects: allocates data
// efficiency: O(n²)
// requirements: the file located at filename exists, is of type .csv, and is
//   formatted correctly
CSV::CSV(string filename) {
  ifstream file(filename);
  string line;
  while (file.good()) {
    line = "";
    getline(file, line);
    contents.push_back(line);
  }
  file.close();
  separateElements();
}

// load(filename) acts as a manually invocable constructor for CSV
void CSV::load(string filename) {
  ifstream file(filename);
  string line;
  while (file.good()) {
    line = "";
    getline(file, line);
    contents.push_back(line);
  }
  file.close();
  separateElements();
}

CSV::~CSV() {

}

// separateElements() takes the elements in each entry of lines and enters them
//   into the 2 dimensional array contents
// effects: allocates data
// efficiency: O(n²)
// requirements: none
void CSV::separateElements() {
  string line = "";
  for (int i = 0; i < contents.size(); i++) {
    for (int j = 0; j < contents[i].size(); j++) {
      line += contents[i][j];
      if (line[line.size() - 1] == ',') {
        line.erase(line.size()-1, 1); // drop the comma
        elements.push_back(line); // add the line to the elements vector
        line = ""; // clear line for the next element
      }
      // catch last element (because there's no comma after it)
      else if (j == contents[i].size()-1) {
        elements.push_back(line);
        line = "";
      }
    }
  }
}

void CSV::printLines() {
  for (int i = 0; i < contents.size(); i++) {
    cout << contents[i] << endl;
  }
  cout << endl;
}

void CSV::printElements() {
  for (int i = 0; i < elements.size(); i++) {
    cout << elements[i] << " ";
  }
  cout << endl;
  //if (elements.size() > 0) cout << elements[elements.size() - 1] << endl;
}

int CSV::getElement(int x, int y) {
  char c = contents[y][x*2];
  int j = c;
  return j - 48;
}
