#ifndef CPPDATASTRUCTURES_LINKED_LIST_H_
#define CPPDATASTRUCTURES_LINKED_LIST_H_

#include "list.h"

class LinkedList: public List {
public:
  virtual int foo(){
    return 1;
  }
};

#endif
