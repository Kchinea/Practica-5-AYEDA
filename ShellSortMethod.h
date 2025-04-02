#ifndef SHELL_SORT_METHOD_H
#define SHELL_SORT_METHOD_H

#include "SortMethod.h"

template <class Key>
class ShellSortMethod : public SortMethod<Key> {
 private:
  double alfa_;
 public:
  ShellSortMethod(StaticSequence<Key>& sequence, double alfa) : SortMethod<Key>(sequence), alfa_(alfa) {}
  void Sort() override {
    int n = this->sequence_.Size();  // Obtener tamaño de la secuencia
    int gap = n;

    while (gap > 1) {
      gap = static_cast<int>(gap * alfa_);
      if (gap < 1) gap = 1;

      for (int i = gap; i < n; i++) {
        Key temp = this->sequence_[i];  // Acceder al operador []
        int j = i;
        while (j >= gap && this->sequence_[j - gap] > temp) {
          this->sequence_[j] = this->sequence_[j - gap];
          j -= gap;
        }
        this->sequence_[j] = temp;
      }
    }
  }
};

#endif