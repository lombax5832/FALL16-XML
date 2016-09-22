#include "XMLTable.h"
#include<string>
#include<algorithm>
#include<fstream>


XMLTable::XMLTable(const string input, string output){
	inpFile = input;
	outFile = output;
}

void XMLTable::newRow(string input) {
}

int XMLTable::getCounter(string input) {
	size_t index = getIndex(input);
		if (index != string::npos) {
			return table.at(index).counter;
		}
	return 0;
}

int XMLTable::getTotalElements() {
	int sum = 0;
	for (size_t i = 0; i < table.size(); i++) {
		sum += table.at(i).counter;
	}
	return sum;
}

size_t XMLTable::getIndex(string input) {
	for (size_t i = 0; i < table.size(); i++) {
		if (table.at(i).name == input) {
			return i;
		}
	}
	return string::npos;
}

bool XMLTable::isInTable(string input) {
	if (getIndex(input) != string::npos) {
		return true;
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