#include "btree.h"
#include <set>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <limits.h>

using namespace std;

int getRandomNumber(int low, int high) {
  double percent = (rand() / (static_cast<double>(RAND_MAX) + 1));
  int offset = static_cast<int>(percent * (high - low + 1));
  return low + offset;
}

int main(int argc, char **argv) {
  /*** This next portion was something I used to sort a bunch of chars.  This was 
       what I used to debug my iterator and made it work ***/
  btree<char> astring;
  
  srand(123456);
  
  cout << "Inserting these random chars into the tree..." << endl;
  for(int i = 0; i < 20; i++)
    {
      pair<btree<char>::iterator, bool> result = astring.insert((char) getRandomNumber(65, 106));
      cout << *result.first;
    }
  cout << endl;
  
  cout << "Now printing them sorted..." << endl;
  for(btree<char>::iterator iter = astring.begin(); iter != astring.end(); ++iter)
    cout << *iter;
  cout << endl;
  
  cout << "And again via const iterator..." << endl;
  const btree<char>& refstring = astring;
  btree<char>::const_iterator citer;
  for(citer = refstring.begin(); citer != refstring.end(); ++citer) 
    {
      //      astring.insert((char) RandomNumberGenerator::getRandomNumber(65, 122));
      cout << *citer;
    }
  
  //  for(btree<char>::const_iterator iter = refstring.begin(); !(iter == refstring.end()); ++iter)
  //    cout << *iter;
  cout << endl;
  
  return 0;	
}
