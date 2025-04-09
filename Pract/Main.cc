#include "Parser.h"
#include "StaticSequence.h"
#include "Sorter.h"
#include "NIF.h"
#include <fstream>
#include "FactoryNIF.h"

int main(int argc, char **argv)
{
  Parser parser(argc, argv);
  try
  {
    parser.ParseArgs();
  }
  catch (std::invalid_argument &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  StaticSequence<NIF> mi_vector(parser.GetSize());
  Logger<NIF> logger(parser.GetTrace());
  Sorter sorter(parser, mi_vector, logger);
  if (parser.GetFormIntroduction() == "file")
  {
    std::ifstream file(parser.GetFileName());
    if (!file.is_open())
    {
      std::cerr << "Error al abrir el archivo " << parser.GetFileName() << std::endl;
      return 1;
    }
    std::string input;
    while (!mi_vector.IsFull() && std::getline(file, input))
    {
      NIF nuevo_nif(input);
      mi_vector.Insert(nuevo_nif);
    }

    file.close();
  }
  else if (parser.GetFormIntroduction() == "manual")
  {
    while (!mi_vector.IsFull())
    {
      std::cout << "Añada un DNI al almacenamiento:";
      std::string input;
      std::cin >> input;
      NIF nuevo_nif(input);
      mi_vector.Insert(nuevo_nif);
    }
  }
  else if (parser.GetFormIntroduction() == "random")
  {
    FactoryNIF factory;
    for (int i = 0; i < parser.GetSize(); ++i)
    {
      NIF nuevo_nif = factory.Generate();
      mi_vector.Insert(nuevo_nif);
    }
  }
  else
  {
    std::cerr << "Error: Formato de introducción no soportado." << std::endl;
    return 1;
  }
  mi_vector.Print();
  sorter.Sort();
  mi_vector.Print();
  return 0;
}
