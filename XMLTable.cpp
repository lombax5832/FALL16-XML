#include "XMLTable.h"
#include<string>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include<iostream>


XMLTable::XMLTable(const string &input, const string &output) {
  inpFile = input;
  outFile = output;
}

void XMLTable::newRow(const string &input) {
  Row newRow;
  newRow.counter = 1;
  newRow.name = input;

  table.push_back(newRow);
}

void XMLTable::addElement(const string &input) {
  if (!isInTable(input)) {
    newRow(input);
  } else {
    table.at(getIndex(input)).counter++;
  }
}

int XMLTable::getCounter(const string &input) const {
  size_t index = getIndex(input);
  if (index != string::npos) {
    return table.at(index).counter;
  }
  return 0;
}

int XMLTable::getTotalElements() const {
  int sum = 0;
  for (size_t i = 0; i < table.size(); i++) {
    sum += table.at(i).counter;
  }
  return sum;
}

size_t XMLTable::getIndex(const string &input) const {
  for (size_t i = 0; i < table.size(); i++) {
    if (table.at(i).name == input) {
      return i;
    }
  }
  return string::npos;
}

int XMLTable::getTableWidth() const {
  size_t length = 0;
  for (size_t i = 0; i < table.size(); i++) {
    length = max(length, table.at(i).name.length());
  }
  return length + 1;
}

bool XMLTable::isInTable(const string &input) const {
  if (getIndex(input) != string::npos) {
    return true;
  }
  return false;
}

bool XMLTable::isEmpty() const {
  return table.size() == 0;
}

void XMLTable::populateRowsFromFile() {
  ifstream input(inpFile);

  if (!input) {
    cout << "Could not open file " << inpFile << " for input" << endl;
    exit(1);
  }
  size_t currentPos = 0;
  string currentLine;
  getline(input, currentLine);
  while (!input.eof()) {
    currentPos = currentLine.find("<");
    if (currentPos != string::npos &&
      currentPos != currentLine.find("</")) {

      addElement(extractFromTag(currentLine, currentPos));

    }
    getline(input, currentLine);
  }
}

//Tag example <tag>
string XMLTable::extractFromTag(const string &input, size_t pos) const {
  string output;
  size_t endPos = input.find('>');

  if (endPos == string::npos) {
    return string("");
  }

  output = input.substr(pos + 1, endPos - (pos + 1));
  return output;
}

void XMLTable::toOstream(ostream &ostrm) const {
  int width = getTableWidth();

  for (int i = 0; i < table.size(); i++) {
    ostrm << setw(width) << left << table.at(i).name << table.at(i).counter << endl;
  }
}

void XMLTable::print() const {
  toOstream(cout);
}

void XMLTable::table2File() const {
  ofstream out(outFile);
  toOstream(out);
}