#include <iostream>
#include <iterator>
#include <string>
#include "btree.h"

using namespace std;

int main() {
  btree<int> b;

  int items = 0;
  for (int i = 0; i < 60; ++i) {
    b.insert(i * 70);
    ++items;
  }

  for (int i = 0; i < 60; ++i)
    for (int j = 1; j < 60; ++j) {
      b.insert(i * 70 + j);
      ++items;
    }
  cout << "Items: " << items << endl;
  {
    btree<int>::iterator iter = b.find(4130);
    if (iter != b.end())
      cout << "4130 found\n";
    else
      cout << "4130 not found\n";
  }
  {
    btree<int>::iterator iter = b.find(4129);
    if (iter != b.end())
      cout << "4129 found\n";
    else
      cout << "4129 not found\n";
  }
}
