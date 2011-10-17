##
## Makefile for COMP3171 Deliverable 4
##

## compiler
#CXX = g++-4.3
CXX = g++-4.5
## enable this for Mac OS X
#CXX = g++-4.2

## compiler flags
CXXFLAGS = -Wall -Werror -O2
## enable this for debugging
#CXXFLAGS = -Wall -g

SOURCES = $(wildcard *.cpp)
OBJECTS = $(subst .cpp,,$(SOURCES))

default: test01

## using this target will automagically compile all the *.cpp
## files (hopefully tests) found in the current directory into
## individual binaries
all: $(OBJECTS)

%: %.cpp btree.h btree.tem btree_iterator.h btree_iterator.tem
	$(CXX) $(CXXFLAGS) -o $@ $<

testbtree: btree_iterator.h btree_iterator.tem btree.h btree.tem testbtree.cpp
	$(CXX) $(CPPFLAGS) -DTEST -lboost_unit_test_framework -o testbtree btree.h testbtree.cpp

clean: 
	rm -f *.o a.out core out? $(OBJECTS)
