#ifndef TESTER_H
#define TESTER_H

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
class Tester {
 public:
  Tester(Parser& parser, StaticSequence<Key>& sequence, Logger<Key>& logger)
      : parser_(parser), sequence_(sequence), logger_(logger) {}
  void Test() {
    std::cout << "Testing sorting methods      " << "comparison      " << "Swaps    " << std::endl; 
    StaticSequence<Key> mi_vector(sequence_);
    StaticSequence<Key> mi_vectorShake(sequence_);  
    StaticSequence<Key> mi_vectorHeap(sequence_);    
    StaticSequence<Key> mi_vectorQuick(sequence_);    
    ShakeMethod<Key> shake(mi_vectorShake, mi_vectorShake.Size(), parser_.GetTrace(), logger_);
    InsertionMethod<Key> insertion(mi_vector, mi_vector.Size(), parser_.GetTrace(), logger_);
    HeapMethod<Key> heap(mi_vectorHeap, mi_vectorHeap.Size(), parser_.GetTrace(), logger_);
    QuickSortMethod<Key> quick(mi_vectorQuick, mi_vectorQuick.Size(), parser_.GetTrace(), logger_);
    ShellMethod<Key> shell(sequence_, sequence_.Size(), parser_.GetTrace(), logger_, 0.5);
    shake.Sort();
    heap.Sort();
    quick.Sort();
    insertion.Sort();
    shell.Sort();
    std::cout << "Insertion sort: " << insertion.GetComparisons() << " comparisons, " << insertion.GetSwaps() << " swaps" << std::endl;
    std::cout << "Shake sort: " << shake.GetComparisons() << " comparisons, " << shake.GetSwaps() << " swaps" << std::endl;
    std::cout << "Heap sort: " << heap.GetComparisons() << " comparisons, " << heap.GetSwaps() << " swaps" << std::endl;
    std::cout << "Quick sort: " << quick.GetComparisons() << " comparisons, " << quick.GetSwaps() << " swaps" << std::endl;
    std::cout << "Shell sort: " << shell.GetComparisons() << " comparisons, " << shell.GetSwaps() << " swaps" << std::endl;
  }
  private:
    Parser& parser_;
    StaticSequence<Key>& sequence_;
    Logger<Key>& logger_;
};

#endif