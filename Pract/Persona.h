#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include "NIF.h"

class Persona
{
public:
  Persona() : nombre_(""), apellidos_(""), nif_(NIF()) {}
  Persona(std::string nombre, std::string apellidos, NIF nif)
      : nombre_(nombre), apellidos_(apellidos), nif_(nif) {}
  NIF getNIF() const { return nif_; }
  std::string getName() const { return nombre_; }
  std::string getLastName() const { return apellidos_; }
  bool operator==(const Persona &) const;
  bool operator!=(const Persona &) const;
  bool operator<(const Persona &) const;
  bool operator>(const Persona &) const;
  friend std::ostream &operator<<(std::ostream &os, const Persona &persona);
  bool operator>=(Persona &persona) const
  {
    return !(*this < persona);
  }
  long operator[](int) const;
  long unsigned int size() const;

private:
  std::string nombre_;
  std::string apellidos_;
  NIF nif_;
};

#endif