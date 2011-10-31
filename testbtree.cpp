#include "btree.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE const_string test
#include <boost/test/unit_test.hpp>

#include <utility>
using namespace std;



BOOST_AUTO_TEST_CASE( constructors ) {
    cout << "BOOST TEST: Constructors" << endl;

    btree<long> treenoarg();
    btree<long> tree(99);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 99);
    //BOOST_CHECK_EQUAL(tree.nodeElems(), 0);
    cout << "finished Constructors" << endl;
} 

BOOST_AUTO_TEST_CASE( test_insert_int ) {
    cout << "BOOST TEST: insert int" << endl;

    btree<long> tree(99);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 99);
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

BOOST_AUTO_TEST_CASE( test_iterator_inc_dec ) {
    cout << "BOOST TEST: iterator ++, begin end rev" << endl;

    btree<char> tree(4);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 4);
    BOOST_CHECK_EQUAL(tree.btree_->nodeElems(), 0);

    tree.insert('M');

    tree.insert('P');
    tree.insert('Y');
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
    tree.insert('O');
    tree.insert('X');

    cout << tree << endl;

    btree<char>::iterator it;
    for (it = tree.begin(); it != tree.end(); ++it) {
        cout << " " << *it ;
    }

    cout << endl;
    for (it = --tree.end(); it != tree.begin(); --it) {
        cout << " "; 
        cout << *it ;
    }
        cout << *it ;
    cout << endl;

    btree<char>::const_iterator cit;
    for (cit = tree.begin(); cit != tree.end(); ++cit) {
        cout << " " << *cit ;
    }

    cout << endl;
    for (cit = --tree.end(); cit != tree.begin(); --cit) {
        cout << " "; 
        cout << *cit ;
    }
        cout << *cit ;
    cout << endl;


    btree<char>::reverse_iterator rit;
    for (rit = tree.rbegin(); rit != tree.rend(); ++rit) {
        cout << " " << *rit ;
    }

    cout << endl;

    for (rit = --tree.rend(); rit != tree.rbegin(); --rit) {
        cout << " "; 
        cout << *rit ;
    }
        cout << *rit ;
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
    tree.insert('A');
    tree.insert('A');

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

BOOST_AUTO_TEST_CASE( test_clone) {
    cout << "BOOST TEST: clone" << endl;
    btree<char> tree(4);
    BOOST_CHECK_EQUAL(tree.maxNodeElems_, 4);
    BOOST_CHECK_EQUAL(tree.btree_->nodeElems(), 0);

    tree.insert('M');

    tree.insert('P');
    tree.insert('P');
    tree.insert('X');
    tree.insert('G');
    tree.insert('T');
    tree.insert('T');
    tree.insert('A');

    cout << "tree" << endl;
    cout << tree << endl;
    cout << "tree2" << endl;
    btree<char> tree2 = tree;
    cout << "tree3" << endl;
    btree<char> tree3(tree);

    cout << tree2 << endl;
    cout << tree3 << endl;

    btree<char>::iterator it;
    for (it = tree.begin(); it != tree.end(); ++it) {
        cout << *it;
    }
}

BOOST_AUTO_TEST_CASE( test_int) {
    cout << "BOOST TEST: int" << endl;
    btree<int> b(4);
  b.insert(2);
  b.insert(200);
  b.insert(50);
  b.insert(4);
  b.insert(2);
  b.insert(1200);
  b.insert(150);
  b.insert(14);
  b.insert(12);
  b.insert(11200);
  b.insert(-150);
  b.insert(-14);
  b.insert(212);
  b.insert(-200);
  b.insert(-50);
  b.insert(-4);

    cout << b << endl;

    btree<int>::iterator it;
    for (it = b.begin(); it != b.end(); ++it) {
        cout << *it << endl;
    }

}
