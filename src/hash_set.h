#ifndef CPPDATASTRUCTURES_HASH_SET_H_
#define CPPDATASTRUCTURES_HASH_SET_H_

#include "linked_list.h"

class HashSetIterator : public Iterator {
private:
  LinkedList** table;
  int table_size;
  int current_position;
  Iterator* current_iterator;

public:

  HashSetIterator(LinkedList** table, int table_size) {
    this->table = table;
    this->table_size = table_size;
    this->current_position = 0;
    this->current_iterator = table[0]->iterator();
  }

  virtual bool hasNext() const {
    if (this->current_iterator->hasNext()){
      return true;
    }
    int search_position = this->current_position + 1;
    bool found = false;
    while (!found && search_position < this->table_size) {
      Iterator* it = this->table[search_position]->iterator();
      if (it->hasNext()) {
        found = true;
      }
      delete it;
      search_position += 1;
    }
    return found;
  }

  virtual int next() {
    if (this->current_iterator->hasNext()){
      return this->current_iterator->next();
    }
    delete this->current_iterator;
    this->current_iterator = NULL;

    int search_position = this->current_position + 1;
    while (this->current_iterator == NULL && search_position < this->table_size) {
      Iterator* it = this->table[search_position]->iterator();
      if (it->hasNext()) {
        this->current_iterator = it;
        this->current_position = search_position;
      } else {
        delete it;
        search_position += 1;
      }
    }

    return this->current_iterator->next();
  }

  virtual ~HashSetIterator() {
    delete current_iterator;
  }
};

class HashSet: public Set {
private:
  int table_size;
  LinkedList** table;
  int size_;

public:
  HashSet() {
    this->size_ = 0;
    this->table_size = 10;
    this->table = new LinkedList*[this->table_size];
    for (int i = 0; i < this->table_size; ++i) {
        this->table[i] = new LinkedList();
    }
  }

  virtual void add(const int data) {
    this->innerAdd(data, true);
  }

  virtual int size() const {
    return this->size_;
  }

  virtual bool contains(int value) const {
    int position = this->hash(value);
    return this->table[position]->contains(value);
  }

  virtual void clear() {
    for (int i = 0; i < this->table_size; ++i) {
        this->table[i]->clear();
    }
    this->size_ = 0;
  }

  virtual Iterator* iterator() const {
    return new HashSetIterator(this->table, this->table_size);
  }

  virtual ~HashSet() {
    for (int i = 0; i < this->table_size; ++i) {
        delete this->table[i];
    }
    delete[] this->table;
  }

protected:
  virtual int hash(int value) const {
    return value % this->table_size;
  }

  virtual void innerAdd(int data, bool checkOverflow) {
    int position = this->hash(data);
    if (!this->table[position]->contains(data)){
      this->table[position]->append(data);
      this->size_ += 1;
    }
    if (checkOverflow) {
      this->doCheckOverflow(position);
    }
  }

  virtual void doCheckOverflow(int position) {
    int limit = 5;
    if (this->table[position]->size() > limit) {
      this->rehashEverything();
    }
  }

  virtual void rehashEverything() {
    // backup old table
    LinkedList** old_table = this->table;
    int old_size = this->table_size;

    // create new structure
    this->size_ = 0;
    this->table_size = this->table_size*2;
    this->table = new LinkedList*[this->table_size];
    for (int i = 0; i < this->table_size; ++i) {
      this->table[i] = new LinkedList();
    }

    // copy data and cleanup old table
    for (int i = 0; i < old_size; ++i) {
      Iterator* it = old_table[i]->iterator();
      while (it->hasNext()) {
        this->innerAdd(it->next(), false);
      }
      delete it;
      delete old_table[i];
    }
    delete[] old_table;
  }
};

#endif
