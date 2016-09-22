using namespace std;
#include<iostream>
#include"XMLTable.h"
#include<fstream>

//test
int main() {
  string input("test");
  XMLTable xmltable("input.txt", "output.txt");

  xmltable.populateRowsFromFile();

  xmltable.print();
  xmltable.table2File();
}