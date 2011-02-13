#ifndef CPPDATASTRUCTURES_ARRAY_LIST_H_
#define CPPDATASTRUCTURES_ARRAY_LIST_H_

#include "list.h"

class ArrayListIterator: public Iterator {
private:
  int* array;
  int size;
  int current;

public:
  ArrayListIterator(int* array, int size) {
    this->array = array;
    this->size = size;
    this->current = 0;
  }

  virtual bool hasNext() const {
    return current < size;
  }

  virtual int next() {
    return array[current++];
  }

  virtual ~ArrayListIterator() {
  }
};

class ArrayList: public List {
private:
  int* array;
  int arraySize;
  int currentPosition;

public:
  ArrayList() {
    this->arraySize = 10;
    this->array = new int[this->arraySize];
    this->currentPosition = -1;
  }

  virtual void append(int data) {
    this->currentPosition++;
    if (this->currentPosition == this->arraySize){
      int* copy = new int[this->getNewSize()];
      for (int i = 0; i < this->arraySize; ++i) {
        copy[i] = this->array[i];
      }
      delete[] this->array;
      this->array = copy;
      this->arraySize = this->getNewSize();
    }
    this->array[currentPosition] = data;
  }

  virtual int size() const {
    return currentPosition+1;
  }

  virtual bool contains(int value) const {
    int current = 0;
    while (current <= currentPosition){
      if (this->array[current] == value) {
        return true;
      }
      current += 1;
    }
    return false;
  }

  virtual void clear() {
    this->currentPosition = -1;
  }

  virtual Iterator* iterator() const {
    return new ArrayListIterator(this->array, this->size());
  }

  virtual ~ArrayList(){
    delete[] this->array;
  }

private:
  int getNewSize() {
    return this->arraySize*2;
  }
};

#endif
