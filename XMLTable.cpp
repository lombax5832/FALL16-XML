#include "XMLTable.h"
#include<string>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include<iostream>

XMLTable::XMLTable(const string &input, const string &output) {
  inpFile = input;
  outFile = output;
  populateRowsFromFile();
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
  return length;
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
  // Creates an ifstream object that opens the file that inpFile refers to
  ifstream input(inpFile);

  // Prints an error if the file could not be opened for input
  if (!input) {
    cout << "Could not open file " << inpFile << " for input" << endl;
    exit(1);
  }

  size_t currentPos = 0; // Stores the position of the first "<" substring found
  string currentLine; // Temporarily stores the current line we're looking for a tag in
  getline(input, currentLine);
  while (!input.eof()) {
    currentPos = currentLine.find("<");
    if (currentPos != string::npos && // Make sure a "<" was found in the string
      currentPos != currentLine.find("</")) { // Make sure we didn't get a closing tag

      addElement(extractFromTag(currentLine, currentPos));

    }
    getline(input, currentLine);
  }
  input.close();
}

string XMLTable::extractFromTag(const string &input, size_t startPos) const {
  string output;
  size_t endPos = input.find('>');

  if (endPos == string::npos) {		//If no closing bracket is found, returned string is empty("")
    return string("");
  }

  output = input.substr(startPos + 1, endPos - (startPos + 1));  //Extracts the string from text file
  return output;
}

void XMLTable::toOstream(ostream &ostrm) const {
  int width = getTableWidth() + 1;

  // Runs a loop and outputs a line to an ostream object
  for (size_t i = 0; i < table.size(); i++) {
    ostrm << setw(width) << left << table.at(i).name << table.at(i).counter << endl;
  }
}

void XMLTable::print() const {
  toOstream(cout);
}

void XMLTable::table2File() const {
  ofstream out(outFile);
  toOstream(out);
  out.close();
}