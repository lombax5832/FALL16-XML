using namespace std;
#include<vector>

struct Row
{
	string name;
	int counter;
};

class XMLTable {
public:
	XMLTable(const string input, string output);

	void newRow(string input);

	int getCounter(string input);

	int getTotalElements();

	bool isInTable(string input);

	bool isEmpty();

	void print();

	void table2File();
private:
	vector<Row> table;
	string inpFile;
	string outFile;
};