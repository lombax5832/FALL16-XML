using namespace std;
#include<vector>

struct Row {
  string name;
  int counter;
};

class XMLTable {
public:
  /*
  Purpose: Constructor to create the class XMLTable
  Pre: Two strings to create to files
  Post:
  */
  XMLTable(const string &input, const string &output);

  /*
  Purpose: Creates a new row in the XMLTable to add another tag
  Pre: An XMLTable
  Post: Adds another row into the XMLTable
  */
  void newRow(const string &input);

  /*
  Purpose: Adds another element into the XMLTable. Checks if
    the element is already in the table before creation
  Pre: XMLTable to add the element
  Post: Another element is added to the XMLTable
  */
  void addElement(const string &input);

  /*
  Purpose: Counts the total number of a certain tag in the XMLTable
  Pre: An XMLTable to count the specific tag and the specific tag name
  Post: Returns the tallied number of the specific tag
  */
  int getCounter(const string &input) const;

  /*
  Purpose: Counts the total number of tags in the XMLTable
  Pre: An XMLTable to count how many tags are within
  Post: Returns the total tally of tags in the table
  */
  int getTotalElements() const;

  /*
  Purpose: Determines where a specific tag is within the XMLTable
  Pre: An XMLTable and a specific tag
  Post: Returns the index the tag
  */
  size_t getIndex(const string &input) const;

  /*
  Purpose: Calculates the width of the XMLTable
  Pre: An XMLTable
  Post: Returns the width of the XMLTable
  */
  int getTableWidth() const;

  /*
  Purpose: Checks the XMLTable to see if a tag is within
    the table
  Pre: An XMLTable
  Post: Returns true or false depending on if the tag is within
  the XMLTable
  */
  bool isInTable(const string &input) const;

  /*
  Purpose: Checks if the XMLTable is empty
  Pre: A XMLTable to check 
  Post: Returns true or false depending on whether the
    table is empty or not
  */
  bool isEmpty() const;

  /*
  Purpose:
  Pre:
  Post:
  */
  void populateRowsFromFile();

  /*
  Purpose:
  Pre:
  Post:
  */
  string extractFromTag(const string&, size_t) const;

  /*
  Purpose:
  Pre:
  Post:
  */
  void toOstream(ostream &ostrm) const;

  /*
  Purpose: To print out a XMLTable
  Pre: An XMLTable to print out
  Post: Console prints out the XMLTable
  */
  void print() const;

  /*
  Purpose: Stores the XMLTable into a .txt file
  Pre: An XMLTable to transfer to a file
  Post: A file named out.txt with the contents of the 
    XMLTable
  */
  void table2File() const;

private:
  vector<Row> table;
  string inpFile;
  string outFile;
};