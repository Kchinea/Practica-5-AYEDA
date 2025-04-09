#ifndef SHELLMETHOD_H
#define SHELLMETHOD_H

#include "StaticSequence.h"
#include "SortMethod.h"

template <class Key>
class ShellMethod : public SortMethod<Key>
{
public:
  ShellMethod(StaticSequence<Key> &sequence, unsigned size, bool trace, Logger<Key> &logger, double reductionFactor)
      : SortMethod<Key>(sequence, size, trace, logger), reductionFactor_(reductionFactor)
  {
    if (reductionFactor_ <= 0 || reductionFactor_ >= 1)
    {
      throw std::invalid_argument("El factor de reducción debe estar entre 0 y 1.");
    }
  }
  void Sort() override
  {
    int n = this->sequence_.Size();
    int delta = n;
    while (delta > 1)
    {
      delta = static_cast<int>(delta * reductionFactor_);
      if (delta < 1)
        delta = 1;
      deltasort(delta, n);
    }
  }

private:
  double reductionFactor_;
  void deltasort(int delta, int n)
  {
    this->logger_.PrintCurrentDelta(this->sequence_, delta);
    for (int i = delta; i < n; i++)
    {
      Key x = this->sequence_[i];
      int j = i;
      this->logger_.PrintSequence(this->sequence_, delta);
      this->logger_.PrintComparison(this->sequence_, x, this->sequence_[j - delta]);
      while (j >= delta && x < this->sequence_[j - delta])
      {
        this->sequence_[j] = this->sequence_[j - delta];
        j -= delta;
      }
      this->logger_.PrintMovement(this->sequence_, j, x);
      this->sequence_[j] = x;
    }
  }
};
#endif
