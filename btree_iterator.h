#ifndef BTREE_ITERATOR_H
#define BTREE_ITERATOR_H

#include <iterator>
using namespace std;

/**
 * You MUST implement the btree iterators as (an) external class(es) in this file.
 * Failure to do so will result in a total mark of 0 for this deliverable.
 **/

// iterator related interface stuff here; would be nice if you called your
// iterator class btree_iterator (and possibly const_btree_iterator)

template <typename T>
class btree_iterator {
    typedef ptrdiff_t             difference_type;
    typedef forward_iterator_tag  iterator_category;
    typedef T                     value_type;
    typedef T*                    pointer;
    typedef T&                    reference;

    reference operator*() const;
    pointer operator->() const { return &(operator*()); }
    btree_iterator& operator++();
    bool operator==(const btree_iterator& other) const;
    bool operator!=(const btree_iterator& other) const { return !operator==(other); }

    //btree_iterator(typename 
};

#include "btree_iterator.tem"

#endif
