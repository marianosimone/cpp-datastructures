#ifndef CPPDATASTRUCTURES_ARRAY_STACK_H_
#define CPPDATASTRUCTURES_ARRAY_STACK_H_

#include "stack.h"

class ArrayStack: public Stack {
private:
  int* array;
  int arraySize;
  int currentPosition;

public:
  ArrayStack() {
    this->arraySize = 10;
    this->array = new int[this->arraySize];
    this->currentPosition = -1;
  }

  virtual int top() const {
    return this->array[this->currentPosition];
  }

  virtual int pop() {
    return this->array[this->currentPosition--];
  }

  virtual bool isEmpty() const {
    return currentPosition < 0;
  }

  virtual void push(int data) {
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

  virtual void clear() {
    this->currentPosition = -1;
  }

  virtual ~ArrayStack(){
    delete[] this->array;
  }

private:
  int getNewSize() {
    return this->arraySize*2;
  }
};

#endif
