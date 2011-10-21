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

BOOST_AUTO_TEST_CASE( test_insert_int ) {
    cout << "BOOST TEST: insert int" << endl;

    btree<int> tree(4);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 4);
    BOOST_CHECK_EQUAL(tree.btree_->nodeElems(), 0);

    tree.insert(2);

    tree.insert(8);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);
    tree.insert(5);
    tree.insert(9);
    tree.insert(1);
    tree.insert(35);
    tree.insert(15);
    tree.insert(19);
    tree.insert(119);
    //tree.insert(9);
    cout << tree << endl;

    //cout << tree.nodes.begin()->elem_ << endl;
    cout << "finished test insert int" << endl;
} 

BOOST_AUTO_TEST_CASE( test_insert_char ) {
    cout << "BOOST TEST: insert char" << endl;

    btree<char> tree(4);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 4);
    BOOST_CHECK_EQUAL(tree.btree_->nodeElems(), 0);

    tree.insert('M');

    tree.insert('P');
    tree.insert('X');
    tree.insert('G');
    tree.insert('T');
    tree.insert('B');
    tree.insert('Z');
    tree.insert('N');
    tree.insert('R');
    tree.insert('S');
    tree.insert('W');
    tree.insert('Q');
    tree.insert('V');
    tree.insert('A');
    //tree.insert(1);
    //tree.insert(35);
    //tree.insert(15);
    //tree.insert(19);
    //tree.insert(119);
    //tree.insert(9);
    cout << tree << endl;

    //cout << tree.nodes.begin()->elem_ << endl;
    cout << "finished test insert char" << endl;
} 

BOOST_AUTO_TEST_CASE( test_iterator_inc ) {
    cout << "BOOST TEST: iterator ++, begin end" << endl;

    btree<char> tree(4);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 4);
    BOOST_CHECK_EQUAL(tree.btree_->nodeElems(), 0);

    tree.insert('M');

    tree.insert('P');
    tree.insert('X');
    tree.insert('G');
    tree.insert('T');
    tree.insert('A');
    tree.insert('B');
    tree.insert('Z');
    tree.insert('N');
    tree.insert('R');
    tree.insert('S');
    tree.insert('W');
    tree.insert('Q');
    tree.insert('V');
    tree.insert('A');

    cout << tree << endl;
    
    for (btree<char>::iterator it = tree.begin(); it != tree.end(); ++it) {
        cout << " " << *it ;
    }
    cout << endl;

}

BOOST_AUTO_TEST_CASE( test_find ) {
    cout << "BOOST TEST: find" << endl;
    btree<char> tree(4);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 4);
    BOOST_CHECK_EQUAL(tree.btree_->nodeElems(), 0);

    tree.insert('M');

    tree.insert('P');
    tree.insert('X');
    tree.insert('G');
    tree.insert('T');
    tree.insert('A');
    tree.insert('B');

    cout << tree << endl;

    btree<char>::iterator it;
    for (it = tree.begin(); it != tree.end(); ++it) {
        btree<char>::iterator found = tree.find(*it);
        BOOST_CHECK_EQUAL(*found, *it);
    }

    it = tree.find('Z');
    BOOST_CHECK(it == tree.end());

    it = tree.find('C');
    BOOST_CHECK(it == tree.end());
}
