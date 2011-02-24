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

/**
 * A HashSet uses a Hash Function to determine the position in a table,
 * where the value should be inserted.
 * Complexity of insertion is O(1) + O(CollisionResolution),
 * where CollisionResolution is the algorithm used when two values
 * are hashed to the same value
**/
class HashSet: public Set {
protected:
  int table_size;
  LinkedList** table;
  int size_;
  double load_factor_limit;

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

  virtual void doCheckOverflow();

  virtual void rehashEverything();

private:
  void createTable();
  double loadFactor();
};

#endif
