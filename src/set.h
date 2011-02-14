#ifndef CPPDATASTRUCTURES_SET_H_
#define CPPDATASTRUCTURES_SET_H_

#include "iterator.h"

/**
 * A set is a data structure that represents a collection of elements
 * that appear only once
 * This is just an interface for all List implementations, thus
 * it can not be instantiated
**/
class Set {
  public:
    /**
     * Adds value to the set, if it's not already in it
    **/
    virtual void add(int value) = 0;

    /**
     * Returns the number of elements in the set
    **/
    virtual int size() const = 0;

    /**
     * Returns true if the value is a member of the set,
     * false otherwise
    **/
    virtual bool contains(int value) const = 0;

    /**
     * Removes all elements from the set (thus, leaving its size as 0)
    **/
    virtual void clear() = 0;

    /**
     * Returns an Iterator for this Set, which allows
     * iteration over all elements on it.
     * IMPORTANT: Keep in mind that a new instance should be
     * returned in each call, and that the invoker should
     * handle deletion of the Iterator object
    **/
    virtual Iterator* iterator() const = 0;

    virtual ~Set() {}
};

#endif
