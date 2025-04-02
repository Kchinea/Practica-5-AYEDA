#ifndef HEAPMETHOD_H
#define HEAPMETHOD_H


// heap esta mal




#include "StaticSequence.h"
#include "SortMethod.h"  // Asegúrate de incluir esta cabecera

template <class Key>
class HeapMethod : public SortMethod<Key> {  // Asegúrate de heredar correctamente
public:
    // Constructor
    HeapMethod(StaticSequence<Key>& sequence, unsigned size) : SortMethod<Key>(sequence, size) {}

    // Método para ordenar
    void Sort() {
        int n = this->sequence_.Size();

        // Construir un heap máximo
        for (int i = n / 2; i > 0; i--) {
            baja(i, n);
        }

        // Ordenar la secuencia
        for (int i = n; i > 1; i--) {
            // Intercambiar el primer elemento con el último
            Key tmp = this->sequence_[1];
            this->sequence_[1] = this->sequence_[i];
            this->sequence_[i] = tmp;

            // Reestructurar el heap excluyendo el último elemento
            baja(1, i - 1);
        }
    }

private:
    // Función baja (heapify) que garantiza que el subárbol con raíz en i sea un heap
    void baja(int i, int n) {
        while (2 * i <= n) {
            int h1 = 2 * i;
            int h2 = h1 + 1;
            int h;

            // Determinar cuál hijo es el mayor
            if (h2 > n) {
                h = h1;  // Solo hay un hijo
            } else {
                h = (this->sequence_[h1] > this->sequence_[h2]) ? h1 : h2;  // Elegir el hijo mayor
            }

            // Si el padre es mayor o igual que el hijo mayor, no hacer nada
            if (this->sequence_[h] <= this->sequence_[i]) {
                break;
            } else {
                // Intercambiar los elementos utilizando una variable temporal
                Key tmp = this->sequence_[i];
                this->sequence_[i] = this->sequence_[h];
                this->sequence_[h] = tmp;

                i = h;  // Seguir con el siguiente subárbol
            }
        }
    }
};

#endif  // HEAPMETHOD_H
