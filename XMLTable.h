using namespace std;
#include<vector>

struct Row {
  string name;
  int counter;
};

class XMLTable {
public:
  XMLTable(const string& input, const string& output);

  void newRow(const string& input);

  void addElement(const string& input);

  int getCounter(const string& input) const;

  int getTotalElements() const;

  size_t getIndex(const string& input) const;

  int getTableWidth() const;

  bool isInTable(const string& input) const;

  bool isEmpty() const;

  void toOstream(ostream& ostrm) const;

  void print() const;

  void table2File() const;
private:
  vector<Row> table;
  string inpFile;
  string outFile;
};