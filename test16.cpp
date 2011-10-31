#include "btree.h"
#include <set>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <limits.h>

using namespace std;

int getRandomNumber(int low, int high) {
  double percent = (rand() / (static_cast<double>(RAND_MAX) + 1));
  int offset = static_cast<int>(percent * (high - low + 1));
  return low + offset;
}

static const int kMinInteger = 1000000;
static const int kMaxInteger = 9999999;

static void insertRandomNumbers(btree<int>& testContainer, set<int>& stableContainer);
static int confirmEverythingMatches(const btree<int>& testContainer, const set<int>& stableContainer);

/**
 * Tries to insert one million numbers into the 
 * specified test container, and every time the insertion 
 * succeeds (because the number wasn't previously in the btree), 
 * the same number is inserted into the off-the-shelf set 
 * class instance so we can later track the correctness of our btree.
 */
static void insertRandomNumbers(btree<int>& testContainer, set<int>& stableContainer)
{
  // cout << "Let's insert up to 9000000 seven-digit numbers." << endl;
  // cout << endl;
  srand(78439957);
  for (int i = 0; i < 1000000; i++) {
    int randomNum = getRandomNumber(kMinInteger, kMaxInteger);
    pair<btree<int>::iterator, bool> result = testContainer.insert(randomNum);
    if (result.second) stableContainer.insert(randomNum);
    //    if ((i + 1) % 10000 == 0) cout << "Inserted some " << (i+1) << " numbers thus far." << endl;
  }
}

/**
 * Confirms that the specified btree and the specified 
 * set contain exactly the same numbers.  This does so by 
 * considering all numbers that could have been added, and 
 * asserting that each of those numbers is either present 
 * in or absent from both containers.  If all checks out, 
 * we return 0 to signal success; if along the way we see 
 * an integer in one container and not the other, then 
 * we bail immediately and return one to express failure.
 */

static int confirmEverythingMatches(const btree<int>& testContainer, const set<int>& stableContainer)
{
  cout << "Confirms the btree contains the correct numbers...\n";
  for (int j = kMinInteger; j <= kMaxInteger; j++) {
    bool foundInTree = !(testContainer.find(j) == testContainer.end());
    bool foundInSet = (stableContainer.find(j) != stableContainer.end());
    if (foundInTree != foundInSet) {
      cout << "btree is missing items." << endl; 
      return 1;
    }
  }
  cout << "btree checks out just fine." << endl;
  
  return 0;
}

int main(int argc, char **argv)
{
  /*** This is the given testing mechanism.  My code works, so I'm "if-ing" it out...
       during string test.  I could comment it out, but I dislike the compiler warnings
       about unused functions... ***/
  btree<int> testContainer;
  set<int> stableContainer;
  
  insertRandomNumbers(testContainer, stableContainer);
  return confirmEverythingMatches(testContainer, stableContainer);
}
