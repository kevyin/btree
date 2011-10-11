/**
 * The btree is a linked structure which operates much like
 * a binary search tree, save the fact that multiple client
 * elements are stored in a single node.  Whereas a single element
 * would partition the tree into two ordered subtrees, a node 
 * that stores m client elements partition the tree 
 * into m + 1 sorted subtrees.
 */

#ifndef BTREE_H
#define BTREE_H

#ifdef TEST
#define private public
#endif

#include <iostream>
#include <cstddef>
#include <utility>
#include <deque>
#include <set>

namespace Const {
    const int null = 0;
}

// we better include the iterator
#include "btree_iterator.h"

// we do this to avoid compiler errors about non-template friends
// what do we do, remember? :)
template <typename T> class btree;
template <typename T> std::ostream& operator<<(std::ostream& os, const btree<T>& tree);

template <typename T> 
class btree {
    public:
        /** Hmm, need some iterator typedefs here... friends? **/
        friend class btree_iterator<T>;
        typedef btree_iterator<T> iterator;
        //typedef btree_iterator<T> const_iterator;

        /**
         * Constructs an empty btree.  Note that
         * the elements stored in your btree must
         * have a well-defined zero-arg constructor,
         * copy constructor, operator=, and destructor.
         * The elements must also know how to order themselves
         * relative to each other by implementing operator<
         * and operator==. (These are already implemented on
         * behalf of all built-ins: ints, doubles, strings, etc.)
         * 
         * @param maxNodeElems the maximum number of elements
         *        that can be stored in each B-Tree node
         */
        btree(size_t maxNodeElems = 40);

        /**
         * The copy constructor and  assignment operator.
         * They allow us to pass around B-Trees by value.
         * Although these operations are likely to be expensive
         * they make for an interesting programming exercise.
         * Implement these operations using value semantics and 
         * make sure they do not leak memory.
         */

        /**
         * Creates a new B-Tree as a copy of original.
         *
         * @param original a const reference to a B-Tree object
         */
        btree(const btree<T>& original);

        /**
         * Replaces the contents of this object with a copy of rhs.
         *
         * @param rhs a const reference to a B-Tree object
         */
        btree<T>& operator=(const btree<T>& rhs);

        /**
         * Puts a breadth-first traversal of the B-Tree onto the output
         * stream os. Elements must, in turn, support the output operator.
         * Elements are separated by space. Should not output any newlines.
         *
         * @param os a reference to a C++ output stream
         * @param tree a const reference to a B-Tree object
         * @return a reference to os
         */
        friend std::ostream& operator<< <T> (std::ostream& os, const btree<T>& tree);

        /**
         * The following can go here
         * -- end() 
         * -- rbegin() 
         * -- rend() 
         */

        //iterator begin() { return iterator(head_) } 
         
        /**
         * Returns an iterator to the matching element, or whatever 
         * the non-const end() returns if the element could 
         * not be found.  
         *
         * @param elem the client element we are trying to match.  The elem,
         *        if an instance of a true class, relies on the operator< and
         *        and operator== methods to compare elem to elements already 
         *        in the btree.  You must ensure that your class implements
         *        these things, else code making use of btree<T>::find will
         *        not compile.
         * @return an iterator to the matching element, or whatever the
         *         non-const end() returns if no such match was ever found.
         */
        iterator find(const T& elem);

        /**
         * Identical in functionality to the non-const version of find, 
         * save the fact that what's pointed to by the returned iterator
         * is deemed as const and immutable.
         *
         * @param elem the client element we are trying to match.
         * @return an iterator to the matching element, or whatever the
         *         const end() returns if no such match was ever found.
         */
        //const_iterator find(const T& elem) const;

        /**
         * Operation which inserts the specified element
         * into the btree if a matching element isn't already
         * present.  In the event where the element truly needs
         * to be inserted, the size of the btree is effectively
         * increases by one, and the pair that gets returned contains
         * an iterator to the inserted element and true in its first and
         * second fields.  
         *
         * If a matching element already exists in the btree, nothing
         * is added at all, and the size of the btree stays the same.  The 
         * returned pair still returns an iterator to the matching element, but
         * the second field of the returned pair will store false.  This
         * second value can be checked to after an insertion to decide whether
         * or not the btree got bigger.
         *
         * The insert method makes use of T's zero-arg constructor and 
         * operator= method, and if these things aren't available, 
         * then the call to btree<T>::insert will not compile.  The implementation
         * also makes use of the class's operator== and operator< as well.
         *
         * @param elem the element to be inserted.
         * @return a pair whose first field is an iterator positioned at
         *         the matching element in the btree, and whose second field 
         *         stores true if and only if the element needed to be added 
         *         because no matching element was there prior to the insert call.
         */
        std::pair<iterator, bool> insert(const T& elem);

        /**
         * Disposes of all internal resources, which includes
         * the disposal of any client objects previously
         * inserted using the insert operation. 
         * Check that your implementation does not leak memory!
         */
        ~btree(); 


    private:

        typedef int sometype;
        struct Node {
            public:
            Node(const T& e) : elem_(e) { refCount = 0; }
            //Node(const T& e, btreePtr l, btreePtr r) : elem_(e), refCount(0), 
                                                   //left_(l), right_(r) {}
            //Node(const T& e, btree* l, btree* r) : elem_(e), left_(l), right_(r) {}
            ~Node() {
                //cout << "~node" << endl;
                //if (left_ != Const::null) left_->~btree();
                //delete left_;
                //if (right_ != Const::null) right_->~btree();
                //delete right_;
            }
            btree owner; // the btree this node belongs to. 

            friend std::ostream& operator<<(std::ostream& os, const Node& n) {
                os << n.elem_;
                return os;
            }

            friend bool operator< (const Node& l, const Node& r) {
                return l.elem_ < r.elem_;
            }

            T       elem_;
            btree   left_;
            btree   right_;

            private:
            int refCount;
        };

        struct NodePtr {
            public:
            Node* operator->() { return n_; }
            Node* operator->() const { return n_; }
            Node& operator*() { return *n_; }
            Node& operator*() const { return *n_; }

            NodePtr() : n_(Const::null) {}
            NodePtr(Node* n) : n_(n) { ++n_->refCount; }
            ~NodePtr() { if (!isNull() && --n_->refCount == 0) delete n_; }
            NodePtr(const NodePtr& rhs) : n_(rhs.n_) { if (!isNull()) ++n_->refCount; }
            NodePtr& operator=(const NodePtr& rhs) {
                if (n_ == rhs.n_) 
                    return *this;
                if (!isNull() && --n_->refCount == 0)
                    delete n_;

                n_ = rhs.n_;
                if (!isNull()) ++n_->refCount;
                return *this;
            }
                

            friend bool operator< (const NodePtr& l, const NodePtr& r) {
                return *l < *r;
            }

            friend std::ostream& operator<<(std::ostream& os, const NodePtr& np) {
                os << *np;
                return os;
            }

            private:
            bool isNull() { return n_ == Const::null; }
            Node* n_;
        };

        struct bt_ {
            // Types
            //typedef deque<Node>                     nodes_type;
            typedef set<NodePtr>                    nodes_type;
            typedef typename nodes_type::iterator   nodes_iterator_type;
            //typedef std::pair<iterator, bool>       insert_res_type;
           
            bt_(size_t max) : maxNodeElems(max) {
                nodes_type nodes();
            }


            NodePtr top_left_;
            NodePtr top_right_;
            mutable int refCount;

            nodes_type  nodes;
            size_t      maxNodeElems;

            // Functions
            size_t nodeElems() { return nodes.size(); }
            
        };

        // types
        typedef typename bt_::nodes_type     bt_nodes_type;

        bt_* operator->() { return tree_; }
        bt_* operator->() const { return tree_; }
        bt_& operator*() { return *tree_; }
        bt_& operator*() const { return *tree_; }

        //btreePtr() : tree_(Const::null) {}
        //bt_Ptr(bt_* bt) : tree_(bt) { ++tree_->refCount; } 
        //~btreePtr() { if (tree_ != Const::null && --tree_->refCount == 0) delete tree_; }

        //btreePtr(const btreePtr& rhs) : tree_(rhs.tree_) { ++tree_->refCount; }
        //btreePtr& operator=(const btreePtr& rhs) {
            //if (tree_ == rhs.tree_) 
                //return *this;
            //if (tree_ != Const::null && --tree_->refCount == 0)
                //delete tree_;

            //tree_ = rhs.tree_;
            //++tree_->refCount;
            //return *this;
        //}

        // private members
        bt_* tree_;
        size_t maxNodeElems;
        
        // private functions
        bool isNull() { return tree_ == Const::null; }
        size_t nodeElems();

};

/**
 * The template implementation needs to be visible to whatever
 * translation unit makes use of templatized btree methods.
 * The unconventional practice is to #include the implementation
 * file just before the end of the interface (sort of like
 * sneaking it in and hoping it isn't noticed).  Because the
 * .tem file is included here, the .h file is NOT #included in 
 * the .tem file.  We'd otherwise have circular inclusions
 * and the compiler would be peeved.
 */

#include "btree.tem"

#endif
