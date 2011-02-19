#include "linked_stack.h"

LinkedStack::LinkedStack() {
  this->first = this->currentTop = NULL;
}

void LinkedStack::push(const int data) {
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

int LinkedStack::pop() {
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

int LinkedStack::top() const {
  return this->currentTop->getData();
}

bool LinkedStack::isEmpty() const {
  return this->first == NULL;
}

void LinkedStack::clear() {
  LinkedNode* current = this->first;
  while (current != NULL) {
    LinkedNode* next = current->getNext();
    delete current;
    current = next;
  }
  this->first = this->currentTop = NULL;
}

LinkedStack::~LinkedStack() {
  this->clear();
}
