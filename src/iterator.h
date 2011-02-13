#ifndef CPPDATASTRUCTURES_ITERATOR_H_
#define CPPDATASTRUCTURES_ITERATOR_H_

/**
 * An iterator permits iteration over elements of a
 * data structure
 * There are many idioms for iterators, in this implementation,
 * the following is used:
 * while (iterator->hastNext()){
 *   int element = iterator->next()
 *   // do something with element
 *  }
**/
class Iterator {
public:
  virtual bool hasNext() const = 0;
  virtual int next() = 0;
  virtual ~Iterator() {}
};

#endif
