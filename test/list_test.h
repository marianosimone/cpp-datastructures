#include <gtest/gtest.h>
#include "../src/linked_list.h"
#include "../src/array_list.h"

// Factory method template to create lists
template <class T>
List* CreateList();

// Factory for known implementations
template <>
List* CreateList<LinkedList>() {
  return new LinkedList;
};

template <>
List* CreateList<ArrayList>() {
  return new ArrayList;
};

// Test Fixture, for grouping all common functionallity
template <class T>
class ListTest : public testing::Test {
 protected:
  // Calling ctor
  ListTest() : list_(CreateList<T>()) {}
  // And then, dtor
  virtual ~ListTest() { delete list_; }

  List* const list_;
};

