#include "btree.h"
#include <deque>
#include <set>
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
  btree<long> bl(7);
  set<long> stable;
  
  srand(9374593);
  
  cout << "Inserting random numbers..." << endl;
  
  for(int i = 0; i < 300000; ++i) {
    long l = getRandomNumber(kMinInteger, kMaxInteger);
    bl.insert(l);
    stable.insert(l);
  }
   
  deque<long> dq1;
  cout << "Now traverse forward..." << endl;
  for(btree<long>::iterator iter = bl.begin(); iter != bl.end(); ++iter)
    dq1.push_back(*iter);

  deque<long> dq2;
  cout << "Now traverse in reverse..." << endl;
  btree<long>::iterator iter = bl.end();
  --iter;
  for(; iter != bl.begin(); --iter)
    dq2.push_front(*iter);
  dq2.push_front(*iter);
  
  cout << "Compare traversals..." << endl;
  bool match = (dq1.size() == dq2.size() && dq1.size() == stable.size());
  set<long>::const_iterator i3 = stable.begin();
  for(deque<long>::const_iterator i1 = dq1.begin(), i2 = dq2.begin();
      i1 != dq1.end() && match; ++i1, ++i2, ++i3)
    if (*i1 != *i2 || *i1 != *i3)
      match = false;
      
  if (match)
    cout << "Test passed!" << endl;
  else
    cout << "Test failed!" << endl;
      
  return 0;	
}
