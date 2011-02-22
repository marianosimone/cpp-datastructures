#include "custom_function_hash_set.h"

CustomFunctionHashSet::CustomFunctionHashSet(HashFunction* function) {
  this->function = function;
}

CustomFunctionHashSet::~CustomFunctionHashSet() {
  delete function;
}

int CustomFunctionHashSet::hash(int value) const {
  return this->function->hash(value, this->table_size);
}
