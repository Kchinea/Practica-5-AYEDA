#ifndef QUICKSORT_METHOD_H
#define QUICKSORT_METHOD_H

#include "SortMethod.h"

template <class Key>
class QuickSortMethod : public SortMethod<Key> {
public:
    QuickSortMethod(StaticSequence<Key>& sequence, unsigned size) 
        : SortMethod<Key>(sequence, size) {}

    void Sort() override {
        QuickSort(0, this->sequence_.Size() - 1);
    }

private:
    // Función auxiliar para hacer el particionado y la recursión
    void QuickSort(int ini, int fin) {
        int i = ini, f = fin;
        Key p = this->sequence_[(i + f) / 2];  // Elemento pivote

        while (i <= f) {
            while (this->sequence_[i] < p) i++;  // Avanzar i hasta que sea mayor o igual al pivote
            while (this->sequence_[f] > p) f--;  // Retroceder f hasta que sea menor o igual al pivote
            if (i <= f) {
                // Intercambiar los elementos si i <= f
                Key tmp = this->sequence_[i];
                this->sequence_[i] = this->sequence_[f];
                this->sequence_[f] = tmp;
                i++;
                f--;
            }
        }

        // Recursión en las dos mitades
        if (ini < f) QuickSort(ini, f);
        if (i < fin) QuickSort(i, fin);
    }
};

#endif  // QUICKSORT_METHOD_H
