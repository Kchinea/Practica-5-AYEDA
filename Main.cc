#include "Parser.h"
#include "StaticSequence.h"
#include "ShakeMethod.h"
#include "InsertionMethod.h"
#include "HeapMethod.h"
#include "QuickSortMethod.h"

int main(int argc, char **argv) {
  Parser parser(argc, argv);
  try {
    parser.ParseArgs();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  StaticSequence<int> mi_vector(3);
  StaticSequence<std::string> mi_vector_string(5);
  mi_vector.Insert(1);
  mi_vector.Insert(7);
  mi_vector.Insert(3);
  std::cout << mi_vector[0] << std::endl;
  mi_vector[0] = 4;
  std::cout << mi_vector[0] << std::endl;

  // Asegúrate de pasar el tamaño
  QuickSortMethod<int> shake(mi_vector, mi_vector.Size());
  shake.Sort();
  mi_vector.Print();
  return 0;
}


