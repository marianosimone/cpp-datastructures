#ifndef CPPDATASTRUCTURES_LIST_BACKED_SET_H_
#define CPPDATASTRUCTURES_LIST_BACKED_SET_H_

#include "set.h"
#include "list.h"

class ListBackedSet: public Set {
private:
  List* list;

public:
  ListBackedSet();

  virtual void add(const int data);

  virtual int size() const;

  virtual bool contains(int value) const;

  virtual void clear();

  virtual Iterator* iterator() const;

  virtual ~ListBackedSet();
};

#endif
