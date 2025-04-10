#include "Parser.h"
#include "StaticSequence.h"
#include "Sorter.h"
#include "Tester.h"
#include "NIF.h"
#include "Persona.h"
#include <sstream>
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
  StaticSequence<Persona> mi_vector(parser.GetSize());
  Logger<Persona> logger(parser.GetTrace());
  Tester tester(parser, mi_vector, logger);
  if (parser.GetFormIntroduction() == "file")
  {
    std::ifstream file(parser.GetFileName());
    if (!file.is_open())
    {
      std::cerr << "Error al abrir el archivo " << parser.GetFileName() << std::endl;
      return 1;
    }
    std::string input,nif, name, last_name;
    while (!mi_vector.IsFull() && std::getline(file, input))
    {
      std::istringstream stream(input);
      stream >> nif >> name >> last_name;
      NIF nuevo_nif(nif);
      Persona persona(name, last_name, nuevo_nif);
      mi_vector.Insert(persona);
    }

    file.close();
  }
  else if (parser.GetFormIntroduction() == "manual")
  {
    while (!mi_vector.IsFull())
    {
      std::string input, name, last_name;
      std::cout << "Añada una Persona al almacenamiento:" << std::endl;
      std::cout << "Introduzca el NIF: ";
      std::cin >> input;
      std::cout << "Introduzca el nombre: ";
      std::cin >> name;
      std::cout << "Introduzca el apellido: ";
      std::cin >> last_name;
      NIF nuevo_nif(input);
      Persona persona(name, last_name, nuevo_nif);
      mi_vector.Insert(persona);
    }
  }
  else if (parser.GetFormIntroduction() == "random")
  {
    FactoryNIF factory;
    for (int i = 0; i < parser.GetSize(); ++i)
    {
      NIF nuevo_nif = factory.Generate();
      Persona random_person("Nombre", "Apellidos", nuevo_nif);
      mi_vector.Insert(random_person);
    }
  }
  else
  {
    std::cerr << "Error: Formato de introducción no soportado." << std::endl;
    return 1;
  }

  mi_vector.Print();
  tester.Test();
  mi_vector.Print();
  return 0;
}
