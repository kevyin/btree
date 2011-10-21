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

template <typename T> class btree;

template <typename T>
class btree_iterator {
    public:
    typedef ptrdiff_t               difference_type;
    typedef forward_iterator_tag    iterator_category;
    typedef T                       value_type;
    typedef T*                      pointer;
    typedef T&                      reference;

    reference operator*() const { return pointee_->elem_; }
    pointer operator->() const { return pointee_; }
    btree_iterator& operator++();
    btree_iterator& operator--();
    bool operator==(const btree_iterator& other) const { return this->pointee_ == other.pointee_; } 
    bool operator!=(const btree_iterator& other) const { return !operator==(other); }

    btree_iterator(typename btree<T>::Node *pointee = Const::null) : pointee_(pointee) {}
    btree_iterator(typename btree<T>::Node *pointee, 
                   const typename btree<T>::BTreePtr& btptr) : pointee_(pointee),
                                                        btree_(btptr.btree_) {}
    private:
    typename btree<T>::Node *pointee_;
    const typename btree<T>::BTree* btree_;
};

template <typename T>
class btree_reverse_iterator {
    public:
    typedef ptrdiff_t               difference_type;
    typedef forward_iterator_tag    iterator_category;
    typedef T                       value_type;
    typedef T*                      pointer;
    typedef T&                      reference;

    reference operator*() const { return pointee_->elem_; }
    pointer operator->() const { return pointee_; }
    btree_reverse_iterator& operator++();
    btree_reverse_iterator& operator--();
    bool operator==(const btree_reverse_iterator& other) const { return this->pointee_ == other.pointee_; }
    bool operator!=(const btree_reverse_iterator& other) const { return !operator==(other); }

    btree_reverse_iterator(typename btree<T>::Node *pointee = Const::null) : pointee_(pointee) {}
    private:
    typename btree<T>::Node *pointee_;
};

#include "btree_iterator.tem"

#endif
