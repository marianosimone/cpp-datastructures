#ifndef CPPDATASTRUCTURES_LINKED_LIST_H_
#define CPPDATASTRUCTURES_LINKED_LIST_H_

#include "list.h"

class LinkedNode {
private:
  LinkedNode* next;
  int data;

public:
  LinkedNode() {
    this->next = NULL;
  }

  LinkedNode(const int data) {
    this->next = NULL;
    this->data = data;
  }

  void setData(const int data) {
    this->data = data;
  }

  int getData() const {
    return this->data;
  }

  void setNext(LinkedNode* next) {
    this->next = next;
  }

  bool hasNext() const {
    return this->next != NULL;
  }

  LinkedNode* getNext() const {
    return this->next;
  }
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

  virtual void clear() {
    LinkedNode* current = this->first;
    while (current != NULL) {
      LinkedNode* next = current->getNext();
      delete current;
      current = next;
    }
    this->first = NULL;
  }

  virtual ~LinkedList() {
    this->clear();
  }
};

#endif
