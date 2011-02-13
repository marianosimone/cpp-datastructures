#ifndef CPPDATASTRUCTURES_LIST_H_
#define CPPDATASTRUCTURES_LIST_H_

#include "iterator.h"

/**
 * A list is a data structure that represents a sequence
 * This is just an interface for all List implementations, thus
 * it can not be instantiated
**/
class List {
  public:
    /**
     * Adds value to the end of the list
    **/
    virtual void append(int value) = 0;

    /**
     * Returns the number of elements in the list
    **/
    virtual int size() const = 0;

    /**
     * Returns true if the value is a member of the list,
     * false otherwise
    **/
    virtual bool contains(int value) const = 0;

    /**
     * Removes all elements from the list (thus, leaving its size as 0)
    **/
    virtual void clear() = 0;

    /**
     * Returns an Iterator for this List, which allows
     * iteration over all elements on it.
     * IMPORTANT: Keep in mind that a new instance should be
     * returned in each call, and that the invoker should
     * handle deletion of the Iterator object
    **/
    virtual Iterator* iterator() const = 0;

    virtual ~List() {}
};

#endif
