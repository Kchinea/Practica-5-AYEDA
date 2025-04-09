#ifndef QUICKSORT_METHOD_H
#define QUICKSORT_METHOD_H

#include "SortMethod.h"

template <class Key>
class QuickSortMethod : public SortMethod<Key> {
 public:
  QuickSortMethod(StaticSequence<Key>& sequence, unsigned size, bool trace, Logger<Key>& logger) 
    : SortMethod<Key>(sequence, size, trace, logger) {}
  void Sort() override {
    QuickSort(0, this->sequence_.Size() - 1);
  }
 private:
  void QuickSort(int ini, int fin) {
    int i = ini, f = fin;
    Key p = this->sequence_[(i + f) / 2];
    while (i <= f) {
      this->logger_.PrintSequence(this->sequence_, i);
      while (this->sequence_[i] < p) i++;
      while (this->sequence_[f] > p) f--;
      if (i <= f) {
        Key tmp = this->sequence_[i];
        this->sequence_[i] = this->sequence_[f];
        this->sequence_[f] = tmp;
        i++;
        f--;
      }
    }
    if (ini < f) QuickSort(ini, f);
    if (i < fin) QuickSort(i, fin);
  }
};
#endif  // QUICKSORT_METHOD_H
