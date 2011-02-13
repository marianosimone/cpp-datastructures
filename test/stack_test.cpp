#include "stack_test.h"

#if GTEST_HAS_TYPED_TEST

// Defining which impls to test
typedef testing::Types< LinkedStack, ArrayStack > impls;

TYPED_TEST_CASE(StackTest, impls);

/* The actual tests
 * Inside the test body we're in the context of the StackTest class,
 * so "this" is an instance of StackTest
 */
TYPED_TEST(StackTest, IsEmptyShouldBeTrueForEmptyStack) {
  EXPECT_TRUE(this->stack_->isEmpty());
}

TYPED_TEST(StackTest, IsEmptyShouldBeFalseAfterPush) {
  this->stack_->push(1);
  EXPECT_FALSE(this->stack_->isEmpty());
}

TYPED_TEST(StackTest, ValueShouldBeTopAfterPush) {
  this->stack_->push(1);
  EXPECT_EQ(1,this->stack_->top());
}

TYPED_TEST(StackTest, ValueShouldBePopAfterOnePushAndStackShouldBeEmpty) {
  this->stack_->push(1);
  EXPECT_EQ(1,this->stack_->pop());
  EXPECT_TRUE(this->stack_->isEmpty());
}

TYPED_TEST(StackTest, ValueShouldBePopAfterManyPushsAndStackShouldBeEmpty) {
  this->stack_->push(1);
  this->stack_->push(2);
  EXPECT_EQ(2,this->stack_->pop());
  EXPECT_FALSE(this->stack_->isEmpty());
  EXPECT_EQ(1,this->stack_->pop());
  EXPECT_TRUE(this->stack_->isEmpty());
}

TYPED_TEST(StackTest, IsEmptyShouldBeTrueAfterClearWithoutValues) {
  this->stack_->clear();
  EXPECT_TRUE(this->stack_->isEmpty());
}

TYPED_TEST(StackTest, IsEmptyShouldBeTrueAfterClearWithOneValue) {
  this->stack_->push(1);
  this->stack_->clear();
  EXPECT_TRUE(this->stack_->isEmpty());
}

TYPED_TEST(StackTest, IsEmptyShouldBeTrueAfterClearWithManyValues) {
  this->stack_->push(1);
  this->stack_->push(2);
  this->stack_->clear();
  EXPECT_TRUE(this->stack_->isEmpty());
}

#endif
