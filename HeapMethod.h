#ifndef HEAPMETHOD_H
#define HEAPMETHOD_H

#include "StaticSequence.h"
#include "SortMethod.h"  // Asegúrate de incluir esta cabecera

template <class Key>
class HeapMethod : public SortMethod<Key> {
public:
    // Constructor
    HeapMethod(StaticSequence<Key>& sequence, unsigned size) : SortMethod<Key>(sequence, size) {}

    // Método para ordenar
    void Sort() override {
        int n = this->sequence_.Size();

        // Construir un heap máximo (usamos índices desde 0)
        for (int i = (n / 2) - 1; i >= 0; i--) {
            baja(i, n);
        }

        // Extraer los elementos del heap uno por uno
        for (int i = n - 1; i > 0; i--) {
            // Intercambiar el primer elemento (máximo) con el último
            Key tmp = this->sequence_[0];
            this->sequence_[0] = this->sequence_[i];
            this->sequence_[i] = tmp;

            // Reestructurar el heap sin el último elemento
            baja(0, i);
        }
    }

private:
    // Función baja (heapify) que garantiza que el subárbol con raíz en i sea un heap
    void baja(int i, int n) {
        int h1, h2, h;
        
        while ((h1 = 2 * i + 1) < n) {  // Primer hijo
            h2 = h1 + 1;  // Segundo hijo
            h = (h2 < n && this->sequence_[h2] > this->sequence_[h1]) ? h2 : h1;

            // Si el padre es mayor o igual al mayor de sus hijos, no hacer nada
            if (this->sequence_[i] >= this->sequence_[h]) {
                break;
            }

            // Intercambiar padre con el hijo mayor
            Key tmp = this->sequence_[i];
            this->sequence_[i] = this->sequence_[h];
            this->sequence_[h] = tmp;

            i = h;  // Continuar con el subárbol afectado
        }
    }
};

#endif  // HEAPMETHOD_H
