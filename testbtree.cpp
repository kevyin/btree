#include "btree.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE const_string test
#include <boost/test/unit_test.hpp>

#include <utility>
using namespace std;



BOOST_AUTO_TEST_CASE( constructors ) {
    cout << "BOOST TEST: Constructors" << endl;

    btree<int> tree(4);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 4);
    //BOOST_CHECK_EQUAL(tree.nodeElems(), 0);
    cout << "finished Constructors" << endl;
} 

BOOST_AUTO_TEST_CASE( test_insert ) {
    cout << "BOOST TEST: insert" << endl;

    btree<int> tree(4);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 4);
    BOOST_CHECK_EQUAL(tree.btree_->nodeElems(), 0);

    tree.insert(2);

    tree.insert(8);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    cout << tree << endl;

    //cout << tree.nodes.begin()->elem_ << endl;
    cout << "finished test insert " << endl;
} 
