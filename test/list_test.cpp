#include "list_test.h"

#if GTEST_HAS_TYPED_TEST

// Defining which impls to test
typedef testing::Types< LinkedList, ArrayList > impls;

TYPED_TEST_CASE(ListTest, impls);

// The actual tests
// Inside the test body we're in the context of the ListTest class,
// so "this" is an instance of ListTest
TYPED_TEST(ListTest, Foo) {
  EXPECT_EQ(1, this->list_->foo());
}

#endif  // GTEST_HAS_TYPED_TEST
