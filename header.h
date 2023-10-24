#ifndef HEADER_H
#define HEADER_H

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//table struct so we can store each table
struct Table {
  string name;
  vector<string> attributes;
  vector<string> keys;
  unordered_map<string, vector<string>> data;

  //constructor 
  Table(const string& tableName, const vector<string>& tableAttributes, const vector<string>& tableKeys)
    : name(tableName), attributes(tableAttributes), keys(tableKeys) {}
};

vector<string> getAttributes(string file)
{
  string line = "", temp;
  vector<string> attributeList;

  ifstream fin; 
  fin.open(file.c_str());
  getline(fin, line);
  stringstream attributes(line);

  while(getline(attributes, temp, ','))
    attributeList.push_back(temp);
  fin.close();
  return attributeList;
}

int getTupleAmount(string file)
{
  string line = "", temp;
  int count = 0;

  ifstream fin; 
  fin.open(file.c_str());
  while(getline(fin, line))
    count++;
  fin.close();
  return --count;
}
//unordered_map<vector<string>>
vector<vector<string>> returnTuples(const string file)
{
  string line = "";
  
  ifstream fin{file};
  vector<vector<string>> tuples;

  getline(fin, line);
  for(string line; getline(fin, line);) 
  {
    stringstream input(move(line));
    vector<string> row;
    if(!tuples.empty()) 
      row.reserve(tuples.front().size());
    for(string value; getline(input, value, ',');) 
      row.push_back(move(value));
    tuples.push_back(move(row));
  }
  
  for(const vector<string>& row : tuples) 
  {
    for(const string& value : row)
      cout << setw(15) << value;
    cout << "\n";
  }
  fin.close();
  return tuples;
}

//creates unordered map using attributes and tuples, essentially creating each collumn. 
unordered_map<string, vector<string>> mapReturn(vector<vector<string>> tuples, vector<string> attributes)
{
  unordered_map<string, vector<string>> resultMap;

  for(int i = 0; i < attributes.size(); i++)
  {
    string key = attributes[i];
    for(int j = 0; j < tuples.size(); j++)
    {
      resultMap[key].push_back(tuples[j][i]);
      //cout << resultMap[key].back() << endl;
    }
  }
  return resultMap;
}

#endif