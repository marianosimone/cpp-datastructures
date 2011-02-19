#ifndef CPPDATASTRUCTURES_LINKED_NODE_H_
#define CPPDATASTRUCTURES_LINKED_NODE_H_

#ifndef NULL
#define NULL (0L)
#endif

class LinkedNode {
private:
  LinkedNode* next;
  int data;

public:
  LinkedNode(const int data);

  int getData() const;

  void setNext(LinkedNode* next);

  bool hasNext() const;

  LinkedNode* getNext() const;
};

#endif
