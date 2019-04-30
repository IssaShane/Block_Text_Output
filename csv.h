#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CSV {
  private:
    vector<string> contents; //lines
    vector<string> elements; // comma-separated elements

  public:
    CSV();
    CSV(string filename);
    ~CSV();
    void separateElements();
    void printLines();
    void printElements();
    int getElement(int x, int y);
    void load(string filename);
};

#endif
