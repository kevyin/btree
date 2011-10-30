#include <iostream>
#include <iterator>
#include <string>
#include "btree.h"

using namespace std;

int main() {
  btree<int> b;
  
  b.insert(1);
  cout << "Done!" << endl;
}
