#include <iostream>
#include <iterator>
#include <string>
#include "btree.h"

using namespace std;

int main() {
  btree<int> b;
  
  for(btree<int>::const_iterator iter = b.begin(); iter != b.end(); ++iter)
    cout << *iter << endl;

  cout << "Done!" << endl;
}
