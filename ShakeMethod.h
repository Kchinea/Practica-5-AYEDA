#ifndef SHAKE_METHOD_H
#define SHAKE_METHOD_H

#include "SortMethod.h"

template <class Key>
class ShakeMethod : public SortMethod<Key> {
 public:
  ShakeMethod(StaticSequence<Key>& sequence, unsigned size, bool trace, Logger<Key>& logger) : 
  SortMethod<Key>(sequence, size, trace, logger) {}

  void Sort() override {
    int n = this->sequence_.Size();
    int left = 0;
    int right = n - 1;
    int cam; 
    while (left < right) {
      cam = left;
      for (int i = left; i < right; i++) {
        if (this->sequence_[i] > this->sequence_[i + 1]) {
          Key temp = this->sequence_[i];
          this->sequence_[i] = this->sequence_[i + 1];
          this->sequence_[i + 1] = temp;
          cam = i;
        }
      }
      right = cam;
      cam = right;
      for (int i = right; i > left; i--) {
        if (this->sequence_[i] < this->sequence_[i - 1]) {
          Key temp = this->sequence_[i];
          this->sequence_[i] = this->sequence_[i - 1];
          this->sequence_[i - 1] = temp;
          cam = i;
        }
      }
      left = cam + 1;
    }
  }
};

#endif
