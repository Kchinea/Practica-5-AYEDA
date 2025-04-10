#ifndef INSERTION_METHOD_H
#define INSERTION_METHOD_H

#include "SortMethod.h"

template <class Key>
class InsertionMethod : public SortMethod<Key>
{
public:
  InsertionMethod(StaticSequence<Key> &sequence, unsigned size, bool trace, Logger<Key> &logger)
      : SortMethod<Key>(sequence, size, trace, logger) {}

  void Sort() override
  {
    int n = this->sequence_.Size();
    for (int i = 1; i < n; i++)
    {
      this->logger_.PrintSequence(this->sequence_, i);
      Key x = this->sequence_[i];
      int j = i - 1;
      while (j >= 0 )
      {
        this->comparisons_++;
        this->logger_.PrintComparison(this->sequence_, x, this->sequence_[j]);
        if (!(x < this->sequence_[j])) break;
        this->swaps_++;
        this->sequence_[j + 1] = this->sequence_[j];
        j--;
      }
      this->logger_.PrintMovement(this->sequence_, j + 1, x);
      this->sequence_[j + 1] = x;
      this->swaps_++;
    }
  }
};

#endif
