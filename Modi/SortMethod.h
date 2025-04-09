#ifndef SORT_METHOD_H
#define SORT_METHOD_H

#include "StaticSequence.h"
#include "Logger.h"


template <class Key>
class SortMethod {
public:
  SortMethod(StaticSequence<Key>& sequence, unsigned size, bool trace, Logger<Key>& logger) : 
  sequence_(sequence), size_(size), trace_(trace), logger_(logger){}
  virtual void Sort() = 0;
protected:
  StaticSequence<Key>& sequence_;
  unsigned size_;
  bool trace_;
  Logger<Key>& logger_;
};

#endif
