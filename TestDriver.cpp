using namespace std;
#include<iostream>
#include"XMLTable.h"

//test
int main() {
  XMLTable xmltable("input.txt", "output.txt");
  xmltable.print();
  xmltable.table2File();
  cout << "Read a total of " << xmltable.getTotalElements() << " opening XML tags." << endl;
}