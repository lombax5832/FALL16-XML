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

	void addElement(string input);

	int getCounter(string input) const;

	int getTotalElements() const;

	size_t getIndex(string input) const;

	int getTableWidth() const;

	bool isInTable(string input) const;

	bool isEmpty() const;

	void print() const;

	void table2File() const;
private:
	vector<Row> table;
	string inpFile;
	string outFile;
};