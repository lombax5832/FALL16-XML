using namespace std;
#include<iostream>
#include"XMLTable.h"

//test
int main() {
  int ph;
  string input("");
  string output("");
  XMLTable xmltable(input, output);

  xmltable.addElement("Hello");
  xmltable.addElement("Alpha");
  xmltable.addElement("Alpha");
  xmltable.addElement("Beta");
  xmltable.addElement("Hello");
  xmltable.addElement("Hello1234");
  xmltable.addElement("Alpha");

  xmltable.print();

  cin >> ph;
}