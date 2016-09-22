#include "XMLTable.h"
#include<string>
#include<algorithm>


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
	int sum = 0;
	for (size_t i = 0; i < table.size(); i++) {
		sum += table.at(i).counter;
	}
	return sum;
}

bool XMLTable::isInTable(string input) {
	for (size_t i = 0; i < table.size(); i++) {
		if (table.at(i).name == input) {
			return true;
		}
	}
	return false;
}

bool XMLTable::isEmpty() {
	if (table.size() == 0) {
		return true;
	}
	return false;
}

void XMLTable::print() {
}

void XMLTable::table2File() {
}
