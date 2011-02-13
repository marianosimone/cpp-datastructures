#ifndef CPPDATASTRUCTURES_LINKED_STACK_H_
#define CPPDATASTRUCTURES_LINKED_STACK_H_

#include "stack.h"
#include "linked_node.h"

class LinkedStack: public Stack {
private:
  LinkedNode* first;
  LinkedNode* currentTop;

public:
  LinkedStack() {
    this->first = this->currentTop = NULL;
  }

  virtual void push(const int data) {
    LinkedNode* newNode = new LinkedNode(data);
    this->currentTop = newNode;

    if (this->first == NULL) {
      this->first = newNode;
      return;
    }
    LinkedNode* insertionPoint = this->first;
    while (insertionPoint != NULL) {
      if (insertionPoint->hasNext()) {
        insertionPoint = insertionPoint->getNext();
      } else {
        insertionPoint->setNext(newNode);
        insertionPoint = NULL;
      }
    }
  }

  virtual int pop() {
    int topValue = this->top();
    if (this->currentTop == this->first) {
      delete this->first;
      this->first = this->currentTop = NULL;
    } else {
      LinkedNode* current = this->first;
      while (current->getNext() != this->currentTop) {
        current = current->getNext();
      }
      LinkedNode* tmp = this->currentTop;
      this->currentTop = current;
      delete tmp;
    }
    return topValue;
  }

  virtual int top() const {
    return this->currentTop->getData();
  }

  virtual bool isEmpty() const {
    return this->first == NULL;
  }

  virtual void clear() {
    LinkedNode* current = this->first;
    while (current != NULL) {
      LinkedNode* next = current->getNext();
      delete current;
      current = next;
    }
    this->first = this->currentTop = NULL;
  }

  virtual ~LinkedStack() {
    this->clear();
  }
};

#endif
