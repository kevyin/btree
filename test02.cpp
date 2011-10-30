#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include "btree.h"

using namespace std;

template <typename T>
void find_in_tree(const btree<T> &b, T val) {
  typename btree<T>::const_iterator iter =
    find(b.begin(), b.end(), val);
  if (iter == b.end()) 
    cout << val << " not found" << endl;
  else
    cout << val << " found" << endl;
}

int main() {
  btree<string> bs(3);
  
  bs.insert("comp3000");
  bs.insert("comp3171");
  bs.insert("comp2000");
  bs.insert("comp1000");
  bs.insert("acomp3000");
  bs.insert("acomp3171");
  bs.insert("acomp2000");
  bs.insert("bcomp1000");
  bs.insert("ccomp3000");
  bs.insert("dcomp3171");
  bs.insert("ecomp2000");
  bs.insert("fcomp1000");
  
  find_in_tree(bs, string("comp3171"));
  
  btree<int> bi(3);
  
  bi.insert(1);
  bi.insert(10);
  bi.insert(3);
  bi.insert(4);
  bi.insert(11);
  bi.insert(110);
  bi.insert(13);
  bi.insert(14);
  bi.insert(-1);
  bi.insert(-10);
  bi.insert(-3);
  bi.insert(-4);
  
  find_in_tree(bi, 100);
}
