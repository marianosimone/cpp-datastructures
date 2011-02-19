#ifndef CPPDATASTRUCTURES_LINKED_STACK_H_
#define CPPDATASTRUCTURES_LINKED_STACK_H_

#include "stack.h"
#include "linked_node.h"

class LinkedStack: public Stack {
private:
  LinkedNode* first;
  LinkedNode* currentTop;

public:
  LinkedStack();

  virtual void push(const int data);

  virtual int pop();

  virtual int top() const;

  virtual bool isEmpty() const;

  virtual void clear();

  virtual ~LinkedStack();
};

#endif
