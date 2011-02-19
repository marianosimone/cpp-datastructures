#ifndef CPPDATASTRUCTURES_LINKED_LIST_H_
#define CPPDATASTRUCTURES_LINKED_LIST_H_

#include "list.h"
#include "linked_node.h"

class LinkedListIterator: public Iterator {
private:
  LinkedNode* current;

public:
  LinkedListIterator(LinkedNode* first);

  virtual bool hasNext() const;

  virtual int next();

  virtual ~LinkedListIterator();
};

class LinkedList: public List {
private:
  LinkedNode* first;

public:
  LinkedList();

  virtual void append(const int data);

  virtual int size() const;

  virtual bool contains(int value) const;

  virtual void clear();

  virtual Iterator* iterator() const;

  virtual ~LinkedList();
};

#endif
