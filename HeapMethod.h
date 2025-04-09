#ifndef HEAPMETHOD_H
#define HEAPMETHOD_H

#include "StaticSequence.h"
#include "SortMethod.h" 

template <class Key>
class HeapMethod : public SortMethod<Key> {
 public:
  HeapMethod(StaticSequence<Key>& sequence, unsigned size) : SortMethod<Key>(sequence, size) {}
  void Sort() override {
    int n = this->sequence_.Size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
      baja(i, n);
    }
    for (int i = n - 1; i > 0; i--) {
      Key tmp = this->sequence_[0];
      this->sequence_[0] = this->sequence_[i];
      this->sequence_[i] = tmp;
      baja(0, i);
    }
  }

 private:
  void baja(int i, int n) {
    int h1, h2, h;
    while ((h1 = 2 * i + 1) < n) {
      h2 = h1 + 1;
      h = (h2 < n && this->sequence_[h2] > this->sequence_[h1]) ? h2 : h1;
      if (this->sequence_[i] >= this->sequence_[h]) {
        break;
      }
      Key tmp = this->sequence_[i];
      this->sequence_[i] = this->sequence_[h];
      this->sequence_[h] = tmp;
      i = h;  
    }
    }
};

#endif  // HEAPMETHOD_H
