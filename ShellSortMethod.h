#ifndef SHELLMETHOD_H
#define SHELLMETHOD_H

#include "StaticSequence.h"
#include "SortMethod.h"

template <class Key>
class ShellMethod : public SortMethod<Key> {
 public:
  ShellMethod(StaticSequence<Key>& sequence, unsigned size, double reductionFactor)
    : SortMethod<Key>(sequence, size), reductionFactor_(reductionFactor) {
    if (reductionFactor_ <= 0 || reductionFactor_ >= 1) {
      throw std::invalid_argument("El factor de reducción debe estar entre 0 y 1.");
    }
  }
  void Sort() override {
    int n = this->sequence_.Size();
    int delta = n;
    while (delta > 1) {
      delta = static_cast<int>(delta * reductionFactor_); 
      if (delta < 1) delta = 1;
      deltasort(delta, n);
    }
  }
 private:
  double reductionFactor_;
  void deltasort(int delta, int n) {
    for (int i = delta; i < n; i++) {
      Key x = this->sequence_[i];
      int j = i;
      while (j >= delta && x < this->sequence_[j - delta]) {
        this->sequence_[j] = this->sequence_[j - delta];
        j -= delta;
      }
      this->sequence_[j] = x;
    }
  }
};
#endif
