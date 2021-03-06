#include "hash_set.h"

HashSetIterator::HashSetIterator(LinkedList** table, int table_size) {
  this->table = table;
  this->table_size = table_size;
  this->current_position = 0;
  this->current_iterator = table[0]->iterator();
}

bool HashSetIterator::hasNext() const {
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

int HashSetIterator::next() {
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

HashSetIterator::~HashSetIterator() {
  delete current_iterator;
}

HashSet::HashSet() {
  this->size_ = 0;
  this->table_size = 10;
  this->load_factor_limit = 0.75;
  this->createTable();
}

void HashSet::add(const int data) {
  this->innerAdd(data, true);
}

int HashSet::size() const {
  return this->size_;
}

bool HashSet::contains(int value) const {
  int position = this->hash(value);
  return this->table[position]->contains(value);
}

void HashSet::clear() {
  for (int i = 0; i < this->table_size; ++i) {
      this->table[i]->clear();
  }
  this->size_ = 0;
}

Iterator* HashSet::iterator() const {
  return new HashSetIterator(this->table, this->table_size);
}

HashSet::~HashSet() {
  for (int i = 0; i < this->table_size; ++i) {
      delete this->table[i];
  }
  delete[] this->table;
}

int HashSet::hash(int value) const {
  return value % this->table_size;
}

/**
 * If the value is not already on its corresponding list,
 * then it's added.
 * After that, if checkOverflow is true, overflow checking is
 * performed and, an overflow is found, the table is recreated,
 * changing some parameter of the hashing function, in order to
 * allow more values to be inserted
**/
void HashSet::innerAdd(int data, bool checkOverflow) {
  int position = this->hash(data);
  if (!this->table[position]->contains(data)){
    this->table[position]->append(data);
    this->size_ += 1;
  }
  if (checkOverflow) {
    this->doCheckOverflow();
  }
}

/**
 * This is a global overflow cheking algorithm.
 * It doesn't depend on how many values hash to a certain one,
 * (if we consider the hash function to be good enough, this
 * kind of checking wouldn't be THAT useful), but on how many
 * values are on the set, in relation with how many elements
 * the hashing space allows 
**/
void HashSet::doCheckOverflow() {
  if (this->loadFactor() > this->load_factor_limit) {
    this->rehashEverything();
  }
}

double HashSet::loadFactor() {
  return ((double)this->size())/table_size;
}

void HashSet::rehashEverything() {
  // backup old table
  LinkedList** old_table = this->table;
  int old_size = this->table_size;

  // create new structure
  this->size_ = 0;
  this->table_size = this->table_size*2;
  this->createTable();

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

void HashSet::createTable() {
  this->table = new LinkedList*[this->table_size];
  for (int i = 0; i < this->table_size; ++i) {
      this->table[i] = new LinkedList();
  }
}
