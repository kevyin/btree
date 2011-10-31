#include <iostream>
#include <iterator>
#include <string>
#include "btree.h"

using namespace std;

int main() {
  btree<int> b(2);
  
  b.insert(1);
  b.insert(10);
  b.insert(-3);
  b.insert(-4);
  b.insert(31);
  b.insert(310);
  b.insert(7);
  b.insert(14);
  b.insert(-1);
  b.insert(-10);
  b.insert(3);
  b.insert(4);
  {
    const btree<int> &b1 = b;
    btree<int>::const_iterator iter = b1.find(5);
    btree<int>::const_iterator iend = b1.end();
    if (iter != iend)
      cout << "5 found\n";
    else
      cout << "5 not found\n";
  }
  {
    const btree<int> &b1 = b;
    btree<int>::const_iterator iter = b1.find(10);
    btree<int>::const_iterator iend = b1.end();
    if (iter != iend)
      cout << "10 found\n";
    else
      cout << "10 not found\n";
  }
}
