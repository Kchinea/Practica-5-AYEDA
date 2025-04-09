#include "Parser.h"
#include "StaticSequence.h"
#include "Sorter.h"
#include "NIF.h"
#include <fstream>  // Para manejar archivos

int main(int argc, char **argv) {
  Parser parser(argc, argv);
  try {
    parser.ParseArgs();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  
  StaticSequence<NIF> mi_vector(parser.GetSize()); 
  Sorter sorter(parser, mi_vector);
  if(parser.GetFormIntroduction() == "file") {
    std::ifstream file(parser.GetFileName());
    if (!file.is_open()) {
      std::cerr << "Error al abrir el archivo " << parser.GetFileName() << std::endl;
      return 1;
    }
    std::string input;
    while (!mi_vector.IsFull() && std::getline(file, input)) {
      NIF nuevo_nif(input);
      mi_vector.Insert(nuevo_nif);
      sorter.Sort();
      mi_vector.Print();
    }
  
    file.close();
  } else if (parser.GetFormIntroduction() == "manual") {
    while(!mi_vector.IsFull()) {
      std::cout << "Añada un DNI al almacenamiento:" ;
      std::string input;
      std::cin >> input;
      NIF nuevo_nif(input);
      mi_vector.Insert(nuevo_nif);
      sorter.Sort();
      mi_vector.Print();
    }
  }
  return 0;
}
