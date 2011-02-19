#include "array_list.h"

ArrayListIterator::ArrayListIterator(int* array, int size) {
  this->array = array;
  this->size = size;
  this->current = 0;
}

bool ArrayListIterator::hasNext() const {
  return current < size;
}

int ArrayListIterator::next() {
  return array[current++];
}

ArrayListIterator::~ArrayListIterator() {
}

ArrayList::ArrayList() {
  this->arraySize = 10;
  this->array = new int[this->arraySize];
  this->currentPosition = -1;
}

void ArrayList::append(int data) {
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

int ArrayList::size() const {
  return currentPosition+1;
}

bool ArrayList::contains(int value) const {
  int current = 0;
  while (current <= currentPosition){
    if (this->array[current] == value) {
      return true;
    }
    current += 1;
  }
  return false;
}

void ArrayList::clear() {
  this->currentPosition = -1;
}

Iterator* ArrayList::iterator() const {
  return new ArrayListIterator(this->array, this->size());
}

ArrayList::~ArrayList() {
  delete[] this->array;
}

int ArrayList::getNewSize() const {
  return this->arraySize*2;
}
