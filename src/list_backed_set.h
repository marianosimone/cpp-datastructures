#ifndef CPPDATASTRUCTURES_LIST_BACKED_SET_H_
#define CPPDATASTRUCTURES_LIST_BACKED_SET_H_

#include "linked_list.h"

class ListBackedSet: public Set {
private:
  List* list;

public:
  ListBackedSet() {
    this->list = new LinkedList;
  }

  virtual void add(const int data) {
    if (!this->contains(data)){
      this->list->append(data);
    }
  }

  virtual int size() const {
    return this->list->size();
  }

  virtual bool contains(int value) const {
    return this->list->contains(value);
  }

  virtual void clear() {
    this->list->clear();
  }

  virtual Iterator* iterator() const {
    return this->list->iterator();
  }

  virtual ~ListBackedSet() {
    delete this->list;
  }
};

#endif
