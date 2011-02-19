#include "set_test.h"

#if GTEST_HAS_TYPED_TEST

// Defining which impls to test
typedef testing::Types< ListBackedSet, HashSet > impls;

TYPED_TEST_CASE(SetTest, impls);

/* The actual tests
 * Inside the test body we're in the context of the SetTest class,
 * so "this" is an instance of SetTest
 */
TYPED_TEST(SetTest, SizeShouldBeZeroOnCreation) {
  EXPECT_EQ(0, this->set_->size());
}

TYPED_TEST(SetTest, SizeShouldBeOneAfterAdd) {
  int limit = 100;
  for (int i = 0; i < limit; ++i){
    this->set_->add(i);
    EXPECT_EQ(i+1, this->set_->size());
  }
}

TYPED_TEST(SetTest, SizeShouldBeSameAfterAddingSameValue) {
  this->set_->add(1);
  this->set_->add(1);
  EXPECT_EQ(1, this->set_->size());
}

TYPED_TEST(SetTest, SizeShouldBeZeroAfterClear) {
  this->set_->add(1);
  this->set_->add(2);
  this->set_->clear();
  EXPECT_EQ(0, this->set_->size());
}

TYPED_TEST(SetTest, InsertionShouldBePossibleAfterClear) {
  this->set_->add(1);
  this->set_->clear();
  this->set_->add(1);
  EXPECT_EQ(1, this->set_->size());
}

TYPED_TEST(SetTest, ContainsShouldBeFalseForEmptySets) {
  EXPECT_FALSE(this->set_->contains(13));
}

TYPED_TEST(SetTest, ContainsShouldBeFalseForValueNotInSet) {
  this->set_->add(1);
  this->set_->add(2);
  EXPECT_FALSE(this->set_->contains(13));
}

TYPED_TEST(SetTest, ContainsShouldBeTrueForOnlyValue) {
  this->set_->add(1);
  EXPECT_TRUE(this->set_->contains(1));
}

TYPED_TEST(SetTest, ContainsShouldBeTrueForFirstValueAdded) {
  this->set_->add(1);
  this->set_->add(2);
  this->set_->add(3);
  EXPECT_TRUE(this->set_->contains(1));
}

TYPED_TEST(SetTest, ContainsShouldBeTrueForSecondValueAdded) {
  this->set_->add(1);
  this->set_->add(2);
  this->set_->add(3);
  EXPECT_TRUE(this->set_->contains(3));
}

TYPED_TEST(SetTest, ContainsShouldBeTrueForValueAtSomePoint) {
  this->set_->add(1);
  this->set_->add(2);
  this->set_->add(3);
  EXPECT_TRUE(this->set_->contains(2));
}

TYPED_TEST(SetTest, NoIterationShouldBeDoneOverEmptySet) {
  Iterator* it = this->set_->iterator();
  EXPECT_FALSE(it->hasNext());
  delete it;
}

TYPED_TEST(SetTest, IterationShouldBeDoneOverOneElementSet) {
  this->set_->add(1);
  Iterator* it = this->set_->iterator();
  EXPECT_TRUE(it->hasNext());
  int element = it->next();
  EXPECT_EQ(1, element);
  EXPECT_FALSE(it->hasNext());
  delete it;
}

TYPED_TEST(SetTest, LongIterationShouldWork) {
  int limit = 200;
  for (int i = 0; i < limit; ++i){
    this->set_->add(i);
  }
  Iterator* it = this->set_->iterator();
  for (int i = 0; i < limit; ++i){
    EXPECT_TRUE(it->hasNext());
    it->next(); // Can't expect, as sets don't preserve order
  }
  EXPECT_FALSE(it->hasNext());
  delete it;
}

#endif