#ifndef CPPDATASTRUCTURES_LIST_H_
#define CPPDATASTRUCTURES_LIST_H_

class List {
  public:
    virtual void append(int) = 0;
    virtual int size() const = 0;
    virtual ~List() {}
};

#endif
