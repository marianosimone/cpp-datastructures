#include <gtest/gtest.h>

#include "../src/set.h"
#include "../src/list_backed_set.h"
#include "../src/hash_set.h"
#include "../src/custom_function_hash_set.h"

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

class ModHashFunction: public HashFunction {
  virtual int hash(int value, int spaceSize) const {
    return value%spaceSize;
  }
};
template <>
Set* CreateSet<CustomFunctionHashSet>() {
  return new CustomFunctionHashSet(new ModHashFunction());
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

