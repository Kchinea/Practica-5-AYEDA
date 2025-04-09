#ifndef FACTORY_NIF_H
#define FACTORY_NIF_H

#include <string>
#include <random>
#include <ctime>
#include <iostream>
#include "NIF.h"

class FactoryNIF {
 public:
  FactoryNIF() {
    srand(static_cast<unsigned>(time(0)));
  }
  NIF Generate() {
    std::string nif_number;
    int first_digit = 1 + (rand() % 9);
    nif_number += std::to_string(first_digit);
    for (unsigned i = 1; i < size_; ++i) {
      int random_digit = rand() % 10;
      nif_number += std::to_string(random_digit);
    }
    char random_letter = static_cast<char>('A' + (rand() % 26)); 
    nif_number += random_letter;
    NIF nif(nif_number);
    return nif;
  }
 private: 
  unsigned size_ = 8;
};

#endif 