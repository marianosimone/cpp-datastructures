#include "list_backed_set.h"
#include "linked_list.h"

ListBackedSet::ListBackedSet() {
  this->list = new LinkedList;
}

void ListBackedSet::add(const int data) {
  if (!this->contains(data)){
    this->list->append(data);
  }
}

int ListBackedSet::size() const {
  return this->list->size();
}

bool ListBackedSet::contains(int value) const {
  return this->list->contains(value);
}

void ListBackedSet::clear() {
  this->list->clear();
}

Iterator* ListBackedSet::iterator() const {
  return this->list->iterator();
}

ListBackedSet::~ListBackedSet() {
  delete this->list;
}
