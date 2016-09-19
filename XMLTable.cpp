#include "XMLTable.h"
#include<string>


XMLTable::XMLTable(const string input, string output){
	inpFile = input;
	outFile = output;
}

void XMLTable::newRow(string input) {
}

int XMLTable::getCounter(string input) {
	return 0;
}

int XMLTable::getTotalElements() {
	return 0;
}

bool XMLTable::isInTable(string input) {
	return false;
}

bool XMLTable::isEmpty() {
	return false;
}

void XMLTable::print() {
}

void XMLTable::table2File() {
}
