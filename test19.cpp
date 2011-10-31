#include "btree.h"
#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;

int getRandomNumber(int low, int high) {
  double percent = (rand() / (static_cast<double>(RAND_MAX) + 1));
  int offset = static_cast<int>(percent * (high - low + 1));
  return low + offset;
}

int main(int argc, char **argv) {
  btree<char> astring(1);
  
  srand(5675678);
  
  cout << "Inserting these random chars into the tree..." << endl;
  for(int i = 0; i < 20; i++)
    {
      pair<btree<char>::iterator, bool> result = astring.insert((char) getRandomNumber(65, 106));
      cout << *result.first;
    }
  cout << endl;
  
  cout << "Now printing them in reverse order..." << endl;
  for(btree<char>::const_reverse_iterator iter = astring.rbegin(); iter != astring.rend(); ++iter)
    cout << *iter;
  cout << endl;
  
  return 0;	
}
