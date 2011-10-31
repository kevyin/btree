#include "btree.h"

using namespace std;

int main(void) {
  btree<char> bt(4);
  
  bt.insert('M');
  bt.insert('X');
  bt.insert('P');
  bt.insert('G');
  bt.insert('T');
  bt.insert('B');
  bt.insert('Z');
  bt.insert('N');
  bt.insert('R');
  bt.insert('S');
  bt.insert('W');
  bt.insert('Q');
  bt.insert('V');
  bt.insert('A');
  bt.insert('C');
  bt.insert('D');
  
  cout << bt << endl;
  
	return 0;	
}
