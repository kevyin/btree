#include <iostream>
#include <iterator>
#include <string>
#include "btree.h"

using namespace std;

class X {
public:
  friend ostream& operator<<(ostream &, const X &);
  X(): i(0) { }
  X(int ii) : i(ii) { }
  bool operator<(const X& x) const { return i < x.i; }
  bool operator==(const X& x) const { return i == x.i; }
  bool operator>(const X& x) const { return i > x.i; }
  bool operator!=(const X& x) const { return i != x.i; }
  bool operator<=(const X& x) const { return i <= x.i; }
  bool operator>=(const X& x) const { return i >= x.i; }
private:
  int i;
};

ostream& operator<<(ostream &out, const X& x) {
  cout << x.i;
  return out;
}

int main() {
  btree<X> b(4);
  
  b.insert(X(2));
  b.insert(X(200));
  b.insert(X(250));
  b.insert(X(4));
  b.insert(X(25));
  b.insert(X(1200));
  b.insert(X(50));
  b.insert(X(-4));
  b.insert(X(-2));
  b.insert(X(-200));
  b.insert(X(500));
  b.insert(X(41));
  b.insert(X(23));
  b.insert(X(200));
  b.insert(X(-50));
  b.insert(X(49));
  b.insert(X(26));
  b.insert(X(2030));
  b.insert(X(150));
  b.insert(X(14));
  b.insert(X(-12));
  b.insert(X(-1200));
  b.insert(X(1500));
  b.insert(X(141));
  b.insert(X(123));
  {
    const btree<X> &b1 = b;
    btree<X>::const_iterator iter = b1.find(X(5));
    btree<X>::const_iterator iend = b1.end();
    if (iter != iend)
      cout << "X(5) found\n";
    else
      cout << "X(5) not found\n";
  }
  {
    const btree<X> &b1 = b;
    btree<X>::const_iterator iter = b1.find(X(50));
    btree<X>::const_iterator iend = b1.end();
    if (iter != iend)
      cout << "X(50) found\n";
    else
      cout << "X(50) not found\n";
  }
}
