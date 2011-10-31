#include <iostream>
#include <iterator>
#include <string>
#include "btree.h"

using namespace std;

int main() {
  btree<int> b;
  b.insert(100);
  b.insert(100);
  b.insert(100);
  b.insert(100);
  b.insert(100);

  for(btree<int>::iterator iter = b.begin(); iter != b.end(); ++iter)
    cout << *iter << endl;
}
