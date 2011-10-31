#include "btree.h"
#include <deque>
#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;

static const int kMinInteger = 1000000;
static const int kMaxInteger = 9999999;

int getRandomNumber(int low, int high) {
  double percent = (rand() / (static_cast<double>(RAND_MAX) + 1));
  int offset = static_cast<int>(percent * (high - low + 1));
  return low + offset;
}

int main(int argc, char **argv) {
  btree<long> bl(3);
  
  srand(2224593);
  
  cout << "Inserting random numbers..." << endl;
  
  for(int i = 0; i < 200; ++i)
    bl.insert(getRandomNumber(kMinInteger, kMaxInteger));

  cout << bl << endl;    
      
  return 0;	
}
