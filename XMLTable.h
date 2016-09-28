using namespace std;
#include<vector>

//Used to keep record of specific tags and the number of times
//they appear in the input file
struct Row {
  string name;
  int counter;
};

class XMLTable {
public:
  /*
    Purpose: Constructor for the class XMLTable
    Pre: Two strings to store file names/locations in the class
    Post: XMLTable object was created
    Parameters:
      &input   = input file name/location
      &output  = input file name/location
  */
  XMLTable(const string &input, const string &output);

  /*
    Purpose: Creates a new row in the XMLTable with given tag name
    Pre: A valid string to input
    Post: Adds another row into the XMLTable
    Parameters:
      &input = string to convert into a Row object and insert into table
  */
  void newRow(const string &input);

  /*
    Purpose: Adds another element into the XMLTable. Checks if
      the element is already in the table before creation
    Pre: XMLTable to add the element
    Post: Another element is added to the XMLTable, or incremented
      if it already exists
    Parameters:
      &input = string to insert or increment in the table
  */
  void addElement(const string &input);

  /*
    Purpose: Counts the total number of a certain tag in the XMLTable
    Pre: An XMLTable to count the specific tag and the specific tag name
    Post: Returns the tallied number of the specific tag
    Parameters:
      &input = string to return the number of times it appeared as
        an XML tag name
  */
  int getCounter(const string &input) const;

  /*
    Purpose: Counts the total number of tags in the XMLTable
    Pre: A valid XMLTable object to count how many tags are within
    Post: Returns the total tally of tags in the table
  */
  int getTotalElements() const;

  /*
    Purpose: Determines where a specific tag is within the XMLTable
    Pre: A valid XMLTable and a specific tag to look for
    Post: Returns the index of the tag in the table
    Parameters:
      &input = string to return the index of
  */
  size_t getIndex(const string &input) const;

  /*
    Purpose: Calculates the width to print the XMLTable
    Pre: A valid XMLTable
    Post: Returns the largest length of all the strings in the table
  */
  int getTableWidth() const;

  /*
    Purpose: Checks the XMLTable to see if a given is within
      the table
    Pre: A valid XMLTable
    Post: Returns true or false depending on if the tag is within
      the XMLTable
    Parameters:
      &input = string to check for existance of in table
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
    Purpose: First it checks to see if the input file can be accessed
      Then adds tag names to table 
    Pre: Properly formatted XML within input file
    Post: Table will be populated with tags and number of times they appear
  */
  void populateRowsFromFile();

  /*
    Purpose: Searches and extracts a XML tag name from a string
    Pre: A string used as the specific search item and the starting
      position of the string
    Post: Either will return the specific string or returns "" if
      no closing bracket ('>') was found
    Parameters:
      &input   = string to extract XML tag name from
      startPos = position of opening bracket ('<') in the input string
  */
  string extractFromTag(const string &input, size_t startPos) const;

  /*
    Purpose: Formats the table to be stored in output.txt
    Pre: Valid ostream object or object derived from ostream, such as ofstream
    Post: Will output formatted lines into the passed ostream
    Parameters:
      &ostrm = ostream object or object derived from ostream to output table to
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
  // Store the table as a vector of Row objects
  vector<Row> table;
  // Store the location/name of the input file
  string inpFile;
  // Store the location/name of the output file
  string outFile;
};