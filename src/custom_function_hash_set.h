#ifndef CPPDATASTRUCTURES_CUSTOM_FUNCTION_HASH_SET_H_
#define CPPDATASTRUCTURES_CUSTOM_FUNCTION_HASH_SET_H_

#include "hash_set.h"

/**
 * A hash function is a stateless object that, given a value and a
 * the size of the space in which it has to map it, returns the
 * mapped value
**/
class HashFunction {
public:
  virtual int hash(int value, int spaceSize) const = 0;
};

class CustomFunctionHashSet: public HashSet {
private:
  HashFunction* function;

public:
  /**
   * function should point to an instance in the heap,
   * as CustomFunctionHashSet will take ownership over it,
   * and dispose it when needed
   * It's recommended that you use the following idiom:
   * CustomFunctionHashSet set(new YourImplementationOfHashFunction());
  **/
  CustomFunctionHashSet(HashFunction* function);

  virtual ~CustomFunctionHashSet();

protected:
  virtual int hash(int value) const;
};

#endif
