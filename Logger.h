#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include "StaticSequence.h"

template <class Key>
class Logger {
 public:
  Logger(bool trace = false) : trace_(trace) {}
  void PrintSequence(StaticSequence<Key>& sequence, int iteration) {
    std::cout << "DEBUG: Actual sequence: ";
    sequence.Print();
  }
  void PrintMovement(StaticSequence<Key>& sequence, int index1, int index2) {
    std::cout << "DEBUG: Curent movement: ";
    sequence.Print();
  }
 private:
  bool trace_;
};

#endif