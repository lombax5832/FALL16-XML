#include "XMLTable.h"
#include<string>
#include<algorithm>
#include<fstream>


XMLTable::XMLTable(const string input, string output){
	inpFile = input;
	outFile = output;
}

void XMLTable::newRow(string input) {
	Row newRow;
	newRow.counter = 0;
	newRow.name = input;

	table.push_back(newRow);
}

void XMLTable::addElement(string input) {
	if (!isInTable(input)) {
		newRow(input);
	} else {
		table.at(getIndex(input)).counter++;
	}
}

int XMLTable::getCounter(string input) const{
	size_t index = getIndex(input);
		if (index != string::npos) {
			return table.at(index).counter;
		}
	return 0;
}

int XMLTable::getTotalElements() const{
	int sum = 0;
	for (size_t i = 0; i < table.size(); i++) {
		sum += table.at(i).counter;
	}
	return sum;
}

size_t XMLTable::getIndex(string input) const{
	for (size_t i = 0; i < table.size(); i++) {
		if (table.at(i).name == input) {
			return i;
		}
	}
	return string::npos;
}

int XMLTable::getTableWidth() const {
	return 0;
}

bool XMLTable::isInTable(string input) const{
	if (getIndex(input) != string::npos) {
		return true;
	}
	return false;
}

bool XMLTable::isEmpty() const{
	if (table.size() == 0) {
		return true;
	}
	return false;
}

void XMLTable::print() const{
}

void XMLTable::table2File() const{
}