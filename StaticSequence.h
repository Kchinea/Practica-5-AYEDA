#ifndef STATIC_SEQUENCE_H_
#define STATIC_SEQUENCE_H_

#include "Sequence.h"

template <class Key>
class StaticSequence : public Sequence<Key> {
  public:
    StaticSequence(const unsigned blocksize) : data_(blocksize), blocksize_(blocksize), to_insert_(0) {}

    bool Search(const Key&) const;
    bool Insert(const Key&);
    bool IsFull() const { return to_insert_ == blocksize_; };
 
  private:
    std::vector<Key> data_;
    unsigned blocksize_;
    unsigned to_insert_;
};

template <class Key>
bool StaticSequence<Key>::Search(const Key& key) const {
  for (int i = 0; i < blocksize_; ++i) {
    if (data_[i] == key) return true;
  }
  return false;
}

template <class Key>
bool StaticSequence<Key>::Insert(const Key& key) {
  if (Search(key) || IsFull()) return false;
  data_[to_insert_++] = key;
  return true;
}

#endif