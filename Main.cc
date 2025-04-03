#include "Parser.h"
#include "StaticSequence.h"
#include "Sorter.h"

int main(int argc, char **argv) {
  Parser parser(argc, argv);
  try {
    parser.ParseArgs();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  StaticSequence<int> mi_vector(3);

  Sorter sorter(parser, mi_vector);
  StaticSequence<std::string> mi_vector_string(5);
  mi_vector.Insert(1);
  mi_vector.Insert(7);
  mi_vector.Insert(3);
  mi_vector[0] = 4;
  mi_vector.Print();
  sorter.Sort();
  mi_vector.Print();
  return 0;
}


