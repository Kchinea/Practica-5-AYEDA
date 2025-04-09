#ifndef STATIC_SEQUENCE_H_
#define STATIC_SEQUENCE_H_

#include "Sequence.h"

template <class Key>
class StaticSequence : public Sequence<Key> {
  public:
    StaticSequence(const unsigned blocksize) : data_(blocksize), blocksize_(blocksize), to_insert_(0) {}

    bool Search(const Key&) const;
    bool Insert(const Key&);
    bool IsFull() const { return to_insert_ == blocksize_; }
    Key operator[](const unsigned pos) const;
    Key& operator[](const unsigned pos);
    void Print() const {
      for (int i = 0; i < blocksize_; ++i) {
        std::cout << data_[i] << " ";
      }
      std::cout << std::endl;
    }
    int Size() const { return blocksize_; }
 
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
  if (IsFull()) return false;
  data_[to_insert_++] = key;
  return true;
}

template <class Key>
Key StaticSequence<Key>::operator[](const unsigned pos) const {
  return data_[pos];
}

template <class Key>
Key& StaticSequence<Key>::operator[](const unsigned pos) {
  return data_[pos];
}


#endif