#ifndef QUICKSORT_METHOD_H
#define QUICKSORT_METHOD_H

#include "SortMethod.h"

template <class Key>
class QuickSortMethod : public SortMethod<Key>
{
public:
  QuickSortMethod(StaticSequence<Key> &sequence, unsigned size, bool trace, Logger<Key> &logger)
      : SortMethod<Key>(sequence, size, trace, logger) {}
  void Sort() override
  {
    QuickSort(0, this->sequence_.Size() - 1);
  }

private:
  void QuickSort(int ini, int fin)
  {
    int i = ini, f = fin;
    Key p = this->sequence_[(i + f) / 2];
    this->logger_.PrintRecursivity(ini, fin, p);
    this->logger_.PrintSequence(this->sequence_, i);
    while (i <= f)
    {
      while (this->sequence_[i] < p)
        i++;
      while (this->sequence_[f] > p)
        f--;
      if (i <= f)
      {
        this->logger_.PrintSwap(this->sequence_, i, f);
        Key tmp = this->sequence_[i];
        this->sequence_[i] = this->sequence_[f];
        this->sequence_[f] = tmp;
        this->logger_.PrintSequence(this->sequence_, i);
        i++;
        f--;
      }
    }
    if (ini < f)
    {
      this->logger_.PrintLeftRecursivity(ini, f);
      QuickSort(ini, f);
    }
    if (i < fin)
    {
      this->logger_.PrintRightRecursivity(i, fin);
      QuickSort(i, fin);
    }
  }
};
#endif // QUICKSORT_METHOD_H
