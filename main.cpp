#include "nf1.h"
#include "output.h"

int Table::tableCount = 0;

int main(){
  const string file = "exampleInputTable.csv";
  const string fileFD = "functionalDependencies.txt";

  // vector<string> result = convertTo1NF(tupleMap);

  Table testTable = Table::parseCSV(file, fileFD);
  // if(is1NF(testTable))
  //   cout << "is 1nf" << endl;
  // else
  //   cout << "is not 1nf" << endl;
  
  //print_map(testTable.data);
  Table result = convertTo1NF(testTable);
  print_map(result.data);

  //print_map(convertTo1NF(tupleMap));



  return 0;
}
