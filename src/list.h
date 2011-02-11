#ifndef CPPDATASTRUCTURES_LIST_H_
#define CPPDATASTRUCTURES_LIST_H_

class List {
  public:
    virtual void append(int value) = 0;
    virtual int size() const = 0;
    virtual bool contains(int value) const = 0;
    virtual void clear() = 0;
    virtual ~List() {}
};

#endif
