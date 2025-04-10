#ifndef HEAPMETHOD_H
#define HEAPMETHOD_H

#include "StaticSequence.h"
#include "SortMethod.h"

template <class Key>
class HeapMethod : public SortMethod<Key>
{
public:
  HeapMethod(StaticSequence<Key> &sequence, unsigned size, bool trace, Logger<Key> &logger) : SortMethod<Key>(sequence, size, trace, logger) {}
  void Sort() override
  {
    int n = this->sequence_.Size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
      this->logger_.PrintSequence(this->sequence_, i);
      baja(i, n);
      this->logger_.PrintSequence(this->sequence_, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
      Key tmp = this->sequence_[0];
      this->sequence_[0] = this->sequence_[i];
      this->sequence_[i] = tmp;
      this->logger_.PrintSwap(this->sequence_, 0, i);
      this->swaps_++;
      this->logger_.PrintSequence(this->sequence_, i);
      baja(0, i);
    }
  }

private:
  void baja(int i, int n)
  {
    int h1, h2, h;
    this->logger_.PrintSequence(this->sequence_, i);
    while ((h1 = 2 * i + 1) < n)
    {
      h2 = h1 + 1;
      h = (h2<n &&this->sequence_[h2]> this->sequence_[h1]) ? h2 : h1;
      this->comparisons_++;
      if (this->sequence_[i] >= this->sequence_[h])
      {
        break;
      }
      Key tmp = this->sequence_[i];
      this->sequence_[i] = this->sequence_[h];
      this->sequence_[h] = tmp;
      this->swaps_++;
      this->logger_.PrintSwapDown(this->sequence_, i, h);
      this->logger_.PrintSequence(this->sequence_, i);
      i = h;
    }
  }
};

#endif 
