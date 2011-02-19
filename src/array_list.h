#ifndef CPPDATASTRUCTURES_ARRAY_LIST_H_
#define CPPDATASTRUCTURES_ARRAY_LIST_H_

#include "list.h"

class ArrayListIterator: public Iterator {
private:
  int* array;
  int size;
  int current;

public:
  ArrayListIterator(int* array, int size);

  virtual bool hasNext() const;

  virtual int next();

  virtual ~ArrayListIterator();
};

class ArrayList: public List {
private:
  int* array;
  int arraySize;
  int currentPosition;

public:
  ArrayList();

  virtual void append(int data);

  virtual int size() const;

  virtual bool contains(int value) const;

  virtual void clear();

  virtual Iterator* iterator() const;

  virtual ~ArrayList();

private:
  int getNewSize() const;
};

#endif
