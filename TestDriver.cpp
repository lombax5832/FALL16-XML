using namespace std;
#include"XMLTable.h"

//test
int main() {
  XMLTable xmltable("input.txt", "output.txt");

  xmltable.populateRowsFromFile();

  xmltable.print();
  xmltable.table2File();
}