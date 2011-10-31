#include <iostream>
#include "btree.h"

using namespace std;

int main() {
  btree<int> *b1 = new btree<int>(3);

  for (int i = 100; i < 200; i += 2)
    (*b1).insert(i);

  for (int i = 100; i > -100; i -= 4)
    (*b1).insert(i);
    
  btree<int> b2 = *b1;
  delete b1;
  btree<int> b3;
  b3 = b2;
  
  for (btree<int>::const_iterator i = b2.begin(); i != b2.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;

  for (btree<int>::iterator i = b3.begin(); i != b3.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
}
