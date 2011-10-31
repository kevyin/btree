#include "btree.h"
#include <set>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  /***A full-scale string test of the tree using iterators, I jacked some code from oag.cc
      and thought kant.g would be a fun file to parse...***/
  btree<string> strTable;
  
  cout << "Reading some strings..." << endl;
  ifstream cityFile("lorem.txt");
  if (!cityFile)
    return 1;  // file couldn't be opened for some reason, abort... 
  
  while (cityFile.good())
    {
      string cityName;
      cityFile >> cityName;
      //      getline(cityFile, cityName);
      strTable.insert(cityName);
    }
  
  cout << "The first 10 strings in order..." << endl;
  // Such beautiful code with iterators...
  btree<string>::iterator iter = strTable.begin();
  for(int i = 0; i < 10 && iter != strTable.end(); i++, iter++) 
    cout << *iter << endl;
  
  return 0;	
}
