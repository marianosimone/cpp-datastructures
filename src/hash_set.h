#ifndef CPPDATASTRUCTURES_HASH_SET_H_
#define CPPDATASTRUCTURES_HASH_SET_H_

#include "set.h"
#include "linked_list.h"

class HashSetIterator : public Iterator {
private:
  LinkedList** table;
  int table_size;
  int current_position;
  Iterator* current_iterator;

public:

  HashSetIterator(LinkedList** table, int table_size);

  virtual bool hasNext() const;

  virtual int next();

  virtual ~HashSetIterator();
};

class HashSet: public Set {
private:
  int table_size;
  LinkedList** table;
  int size_;

public:
  HashSet();

  virtual void add(const int data);

  virtual int size() const;

  virtual bool contains(int value) const;

  virtual void clear();

  virtual Iterator* iterator() const;

  virtual ~HashSet();

protected:
  virtual int hash(int value) const;

  virtual void innerAdd(int data, bool checkOverflow);

  virtual void doCheckOverflow(int position);

  virtual void rehashEverything();

private:
  void createTable();
};

#endif
