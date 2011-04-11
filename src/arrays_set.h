#ifndef CPPDATASTRUCTURES_ARRAYS_SET_H_
#define CPPDATASTRUCTURES_ARRAYS_SET_H_

#include "set.h"
#include "linked_list.h"

/**
 * Extra-efficient implementation for iterations, clear and insertions
 * Based on:
 * http://research.swtch.com/2008/03/using-uninitialized-memory-for-fun-and.html
 * Which, in turn, is based on:
 * https://citeseer.ist.psu.edu/myciteseer/login
 * It has some know limitatios, like:
 *  - Max number of items and max item to be added are hardcoded, thus
 *    the object space MUST be known beforehand (improvement to be done:
 *    auto-resize when adding an element outside range... But it would be
 *    WAY too in-efficient
 *  - Valgrind will complaint about accessing uninitialized memory
 *
**/
class ArraysSetIterator : public Iterator {
private:
  int* dense;
  unsigned int dense_size;
  unsigned int current_position;

public:

  ArraysSetIterator(int* dense, int dense_size);

  virtual bool hasNext() const;

  virtual int next();

  virtual ~ArraysSetIterator();
};

class ArraysSet: public Set {
protected:
  unsigned int dense_size;
  unsigned int current;
  int* dense;
  unsigned int* sparse;

public:
  ArraysSet();

  virtual void add(const int data);

  virtual int size() const;

  virtual bool contains(int value) const;

  virtual void clear();

  virtual Iterator* iterator() const;

  virtual ~ArraysSet();

void print();
};

#endif
