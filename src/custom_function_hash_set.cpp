#include "custom_function_hash_set.h"

CustomFunctionHashSet::CustomFunctionHashSet(HashFunction* function) {
  this->function = function;
}

CustomFunctionHashSet::~CustomFunctionHashSet() {
  delete function;
}

int CustomFunctionHashSet::hash(int value) const {
  // Just delegate this call to the function
  return this->function->hash(value, this->table_size);
}
