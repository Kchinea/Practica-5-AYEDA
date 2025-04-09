#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include "StaticSequence.h"

template <class Key>
class Logger
{
public:
  Logger(bool trace = false) : trace_(trace) {}
  void PrintSequence(StaticSequence<Key> &sequence, int iteration)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Actual sequence: ";
      sequence.Print();
    }
  }
  void PrintMovement(StaticSequence<Key> &sequence, int index1, Key &key)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Moving " << key << " to position " << index1 << std::endl;
    }
  }

  void PrintComparison(StaticSequence<Key> &sequence, Key &key1, Key &key2)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Current comparison: " << key2 << " and " << key1 << std::endl;
    }
  }

  void PrintSwap(StaticSequence<Key> &sequence, int i, int j)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Swapping " << sequence[j] << " and " << sequence[i] << std::endl;
    }
  }

  void PrintCurrentDelta(StaticSequence<Key> &sequence, int delta)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Current delta: " << delta << std::endl;
    }
  }
  void PrintRecursivity(int init, int fin, Key &pivot)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Recursivity: init:" << init << ", end: " << fin << ", pivot: " << pivot << std::endl;
    }
  }
  void PrintLeftRecursivity(int init, int fin)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Left Recursivity: init:" << init << ", end: " << fin << std::endl;
    }
  }
  void PrintRightRecursivity(int init, int fin)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Right Recursivity: init:" << init << ", end: " << fin << std::endl;
    }
  }

  void PrintSwapDown(StaticSequence<Key> &sequence, int i, int j)
  {
    if (trace_)
    {
      std::cout << "DEBUG: Swapping down " << sequence[j] << " and " << sequence[i] << std::endl;
    }
  }

private:
  bool trace_;
};

#endif