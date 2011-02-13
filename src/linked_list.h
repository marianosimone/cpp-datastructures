#ifndef CPPDATASTRUCTURES_LINKED_LIST_H_
#define CPPDATASTRUCTURES_LINKED_LIST_H_

#include "list.h"
#include "linked_node.h"

class LinkedListIterator: public Iterator {
private:
  LinkedNode* current;

public:
  LinkedListIterator(LinkedNode* first) {
    this->current = first;
  }

  virtual bool hasNext() const {
    return current != NULL;
  }

  virtual int next() {
    int res = current->getData();
    current = current->getNext();
    return res;
  }

  virtual ~LinkedListIterator() {}
};

class LinkedList: public List {
private:
  LinkedNode* first;

public:
  LinkedList() {
    this->first = NULL;
  }

  virtual void append(const int data) {
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

  virtual int size() const {
    int size = 0;
    LinkedNode* current = this->first;
    while (current != NULL) {
      size += 1;
      current = current->getNext();
    }
    return size;
  }

  virtual bool contains(int value) const {
    LinkedNode* current = this->first;
    while (current != NULL) {
      if (current->getData() == value) {
        return true;
      }
      current = current->getNext();
    }
    return false;
  }

  virtual void clear() {
    LinkedNode* current = this->first;
    while (current != NULL) {
      LinkedNode* next = current->getNext();
      delete current;
      current = next;
    }
    this->first = NULL;
  }

  virtual Iterator* iterator() const {
    return new LinkedListIterator(this->first);
  }

  virtual ~LinkedList() {
    this->clear();
  }
};

#endif
