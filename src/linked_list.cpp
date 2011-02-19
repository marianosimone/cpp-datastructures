#include "linked_list.h"

LinkedListIterator::LinkedListIterator(LinkedNode* first) {
  this->current = first;
}

bool LinkedListIterator::hasNext() const {
  return current != NULL;
}

int LinkedListIterator::next() {
  int res = current->getData();
  current = current->getNext();
  return res;
}

LinkedListIterator::~LinkedListIterator() {}

LinkedList::LinkedList() {
  this->first = NULL;
}

void LinkedList::append(const int data) {
  LinkedNode* newNode = new LinkedNode(data);
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

int LinkedList::size() const {
  int size = 0;
  LinkedNode* current = this->first;
  while (current != NULL) {
    size += 1;
    current = current->getNext();
  }
  return size;
}

bool LinkedList::contains(int value) const {
  LinkedNode* current = this->first;
  while (current != NULL) {
    if (current->getData() == value) {
      return true;
    }
    current = current->getNext();
  }
  return false;
}

void LinkedList::clear() {
  LinkedNode* current = this->first;
  while (current != NULL) {
    LinkedNode* next = current->getNext();
    delete current;
    current = next;
  }
  this->first = NULL;
}

Iterator* LinkedList::iterator() const {
  return new LinkedListIterator(this->first);
}

LinkedList::~LinkedList() {
  this->clear();
}
