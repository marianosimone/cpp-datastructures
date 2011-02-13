#include "list_test.h"

#if GTEST_HAS_TYPED_TEST

// Defining which impls to test
typedef testing::Types< LinkedList, ArrayList > impls;

TYPED_TEST_CASE(ListTest, impls);

/* The actual tests
 * Inside the test body we're in the context of the ListTest class,
 * so "this" is an instance of ListTest
 */
TYPED_TEST(ListTest, SizeShouldBeZeroOnCreation) {
  EXPECT_EQ(0, this->list_->size());
}

TYPED_TEST(ListTest, SizeShouldBeOneAfterAppend) {
  int limit = 100;
  for (int i = 0; i < limit; ++i){
    this->list_->append(i);
    EXPECT_EQ(i+1, this->list_->size());
  }
}

TYPED_TEST(ListTest, SizeShouldBeZeroAfterClear) {
  this->list_->append(1);
  this->list_->append(2);
  this->list_->clear();
  EXPECT_EQ(0, this->list_->size());
}

TYPED_TEST(ListTest, InsertionShouldBePossibleAfterClear) {
  this->list_->append(1);
  this->list_->clear();
  this->list_->append(1);
  EXPECT_EQ(1, this->list_->size());
}

TYPED_TEST(ListTest, ContainsShouldBeFalseForEmptyLists) {
  EXPECT_FALSE(this->list_->contains(13));
}

TYPED_TEST(ListTest, ContainsShouldBeFalseForValueNotInList) {
  this->list_->append(1);
  this->list_->append(2);
  EXPECT_FALSE(this->list_->contains(13));
}

TYPED_TEST(ListTest, ContainsShouldBeTrueForOnlyValue) {
  this->list_->append(1);
  EXPECT_TRUE(this->list_->contains(1));
}

TYPED_TEST(ListTest, ContainsShouldBeTrueForValueAtBegining) {
  this->list_->append(1);
  this->list_->append(2);
  this->list_->append(3);
  EXPECT_TRUE(this->list_->contains(1));
}

TYPED_TEST(ListTest, ContainsShouldBeTrueForValueAtEnd) {
  this->list_->append(1);
  this->list_->append(2);
  this->list_->append(3);
  EXPECT_TRUE(this->list_->contains(3));
}

TYPED_TEST(ListTest, ContainsShouldBeTrueForValueAtSomePoint) {
  this->list_->append(1);
  this->list_->append(2);
  this->list_->append(3);
  EXPECT_TRUE(this->list_->contains(2));
}

TYPED_TEST(ListTest, NoIterationShouldBeDoneOverEmptyList) {
  Iterator* it = this->list_->iterator();
  EXPECT_FALSE(it->hasNext());
  delete it;
}

TYPED_TEST(ListTest, IterationShouldBeDoneOverOneElementList) {
  this->list_->append(1);
  Iterator* it = this->list_->iterator();
  EXPECT_TRUE(it->hasNext());
  int element = it->next();
  EXPECT_EQ(1, element);
  EXPECT_FALSE(it->hasNext());
  delete it;
}
#endif
