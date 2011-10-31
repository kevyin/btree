#include "btree.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  btree<int> bti(2);

  bti.insert(50);  
  bti.insert(60);  
  bti.insert(10);  
  bti.insert(20);  
  bti.insert(30);  
  bti.insert(40);  
  bti.insert(70);  
  bti.insert(80);  
  bti.insert(100);  
  bti.insert(110);  
  bti.insert(120);  
  
  for(btree<int>::iterator iter = bti.begin(); iter != bti.end(); ++iter)
    *iter += 2;
    
  for(btree<int>::iterator iter = bti.begin(); iter != bti.end(); ++iter)
    cout << *iter << " ";
  cout << endl;
    
  return 0;	
}
