#ifndef CPPDATASTRUCTURES_LINKED_LIST_H_
#define CPPDATASTRUCTURES_LINKED_LIST_H_

#include "list.h"
#include <iostream>
class LinkedList: public List {
public:
  virtual int size(){
    return 0;
  }
};

#endif
