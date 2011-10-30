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
  b.insert(X(50));
  b.insert(X(4));
  b.insert(X(2));
  b.insert(X(1200));
  b.insert(X(150));
  b.insert(X(14));
  b.insert(X(12));
  b.insert(X(11200));
  b.insert(X(-150));
  b.insert(X(-14));
  b.insert(X(212));
  b.insert(X(-200));
  b.insert(X(-50));
  b.insert(X(-4));
  for(btree<X>::iterator iter = b.begin(); iter != b.end(); ++iter)
    cout << *iter << endl;
}
