#ifndef CPPDATASTRUCTURES_LINKED_NODE_H_
#define CPPDATASTRUCTURES_LINKED_NODE_H_

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

#endif
