using namespace std;
#include<iostream>
#include"XMLTable.h"

void isInTableTest(XMLTable, string);

int main() {
  // Make a new XMLTable object with inp.txt as input
  //   and out.txt as output
  XMLTable xmltable("inp.txt", "out.txt");

  // Test XMLTable::isEmpty()
  xmltable.isEmpty() ? cout << "The table is empty."
    : cout << "The table is not empty.";
  cout << endl << endl;

  // Print and output the table to a file
  xmltable.print();
  xmltable.table2File();

  // Test XMLTable::isInTable(string)
  isInTableTest(xmltable, "width");
  isInTableTest(xmltable, "stuff");

  // Test XMLTable::getTotalElements()
  cout << "Read a total of " << xmltable.getTotalElements() 
    << " opening XML tags." << endl;
}

/*
  Simple function to test whether or not a string is 
    stored in a XMLTable object
*/
void isInTableTest(XMLTable xmltable, string input) {
  xmltable.isInTable(input)
    ? cout << "The tag name \"" << input.c_str() << "\" is in the table."
    : cout << "The tag name \"" << input.c_str() << "\" is not in the table.";
  cout << endl;
}