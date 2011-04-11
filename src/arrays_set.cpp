#include "arrays_set.h"

ArraysSetIterator::ArraysSetIterator(int* dense, int dense_size) {
  this->dense = dense;
  this->dense_size = dense_size;
  this->current_position = 0;
}

bool ArraysSetIterator::hasNext() const {
  return this->current_position < this->dense_size;
}

int ArraysSetIterator::next() {
  return this->dense[this->current_position++];
}

ArraysSetIterator::~ArraysSetIterator() {
}

ArraysSet::ArraysSet() {
  unsigned int max_item = 300;
  this->dense = new int[max_item];
  this->sparse = new unsigned int[max_item+1];
  this->dense_size = max_item;
  this->current = 0;
}

void ArraysSet::add(const int data) {
  if (!this->contains(data)){
    this->dense[this->current] = data;
    this->sparse[data] = this->current;
    this->current++;
  }
}

int ArraysSet::size() const {
  return this->current;
}

bool ArraysSet::contains(int value) const {
  return this->sparse[value] < this->dense_size &&
         this->sparse[value] < this->current &&
         this->dense[this->sparse[value]] == value;
}

void ArraysSet::clear() {
  this->current = 0;
}

Iterator* ArraysSet::iterator() const {
  return new ArraysSetIterator(this->dense, this->current);
}

ArraysSet::~ArraysSet() {
  delete[] this->dense;
  delete[] this->sparse;
}

