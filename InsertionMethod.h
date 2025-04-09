#ifndef INSERTION_METHOD_H
#define INSERTION_METHOD_H

#include "SortMethod.h"

template <class Key>
class InsertionMethod : public SortMethod<Key> {
 public:
  InsertionMethod(StaticSequence<Key>& sequence, unsigned size) 
    : SortMethod<Key>(sequence, size) {}

  void Sort() override {
    int n = this->sequence_.Size();
    for (int i = 1; i < n; i++) {
      Key x = this->sequence_[i]; 
      int j = i - 1;
      while (j >= 0 && x < this->sequence_[j]) {
        this->sequence_[j + 1] = this->sequence_[j];
        j--;
      }
      this->sequence_[j + 1] = x;
    }
  }
};

#endif
