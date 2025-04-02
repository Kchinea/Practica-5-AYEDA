#ifndef SORT_METHOD_H
#define SORT_METHOD_H

#include "StaticSequence.h"

template <class Key>
class SortMethod {
public:
  SortMethod(StaticSequence<Key>& sequence, unsigned size) : sequence_(sequence), size_(size) {}
  virtual void Sort() = 0;
protected:
  StaticSequence<Key>& sequence_;
  unsigned size_;
};

#endif
