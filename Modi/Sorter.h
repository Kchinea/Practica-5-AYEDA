#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "StaticSequence.h"
#include "Parser.h"
#include "SortMethod.h"
#include "InsertionMethod.h"
#include "ShakeMethod.h"
#include "HeapMethod.h"
#include "QuickSortMethod.h"
#include "ShellSortMethod.h"
#include "Logger.h"


template <class Key>
class Sorter {
 public:
  Sorter(Parser& parser, StaticSequence<Key>& sequence, Logger<Key>& logger)
      : parser_(parser), sequence_(sequence), logger_(logger) {}
  void Sort() {
    if(parser_.GetTypeOrdenation() == "Insertion") {
      InsertionMethod<Key> insertion(sequence_, sequence_.Size(), parser_.GetTrace(), logger_);
      insertion.Sort();
      sequence_.Print();
    } else if(parser_.GetTypeOrdenation() == "Shake") {
      ShakeMethod<Key> shake(sequence_, sequence_.Size(), parser_.GetTrace(), logger_);
      shake.Sort();
      sequence_.Print();
    } else if(parser_.GetTypeOrdenation() == "Heap") {
      HeapMethod<Key> heap(sequence_, sequence_.Size(), parser_.GetTrace(), logger_);
      heap.Sort();
      sequence_.Print();
    } else if(parser_.GetTypeOrdenation() == "QuickSort") {
      QuickSortMethod<Key> quick(sequence_, sequence_.Size(), parser_.GetTrace(), logger_);
      quick.Sort();
      sequence_.Print();
    } else if(parser_.GetTypeOrdenation() == "Shell") {
      ShellMethod<Key> shell(sequence_, sequence_.Size(), parser_.GetTrace(), logger_, 0.5);
      shell.Sort();
      sequence_.Print();
    } else {
      throw std::invalid_argument("Método de ordenación no soportado.");
    }
  }
  private:
    Parser& parser_;
    StaticSequence<Key>& sequence_;
    Logger<Key>& logger_;
};

#endif