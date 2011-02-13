#include <gtest/gtest.h>

#include "../src/stack.h"
#include "../src/linked_stack.h"
#include "../src/array_stack.h"

// Factory method template to create stacks
template <class T>
Stack* CreateStack();

// Factory for known implementations
template <>
Stack* CreateStack<LinkedStack>() {
  return new LinkedStack;
}

template <>
Stack* CreateStack<ArrayStack>() {
  return new ArrayStack;
}

// Test Fixture, for grouping all common functionallity
template <class T>
class StackTest : public testing::Test {
 protected:
  // Calling ctor
  StackTest() : stack_(CreateStack<T>()) {}
  // And then, dtor
  virtual ~StackTest() { delete stack_; }

  Stack* const stack_;
};

