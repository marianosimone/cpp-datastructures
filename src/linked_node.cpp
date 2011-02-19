#include "linked_node.h"

LinkedNode::LinkedNode(const int data) {
  this->next = NULL;
  this->data = data;
}

int LinkedNode::getData() const {
  return this->data;
}

void LinkedNode::setNext(LinkedNode* next) {
  this->next = next;
}

bool LinkedNode::hasNext() const {
  return this->next != NULL;
}

LinkedNode* LinkedNode::getNext() const {
  return this->next;
}
