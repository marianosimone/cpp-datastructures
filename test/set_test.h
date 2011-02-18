#include <gtest/gtest.h>

#include "../src/set.h"
#include "../src/list_backed_set.h"
#include "../src/hash_set.h"

// Factory method template to create sets
template <class T>
Set* CreateSet();

// Factory for known implementations
template <>
Set* CreateSet<ListBackedSet>() {
  return new ListBackedSet;
}

template <>
Set* CreateSet<HashSet>() {
  return new HashSet;
}

// Test Fixture, for grouping all common functionallity
template <class T>
class SetTest : public testing::Test {
 protected:
  // Calling ctor
  SetTest() : set_(CreateSet<T>()) {}
  // And then, dtor
  virtual ~SetTest() { delete set_; }

  Set* const set_;
};

