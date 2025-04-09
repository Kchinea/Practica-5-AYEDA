#include "Persona.h"

bool Persona::operator==(const Persona &persona) const
{
  return this->nif_ == persona.nif_;
}

bool Persona::operator!=(const Persona &persona) const
{
  return !(*this == persona);
}

bool Persona::operator<(const Persona &persona) const
{
  return this->nif_ < persona.nif_;
}

bool Persona::operator>(const Persona &persona) const
{
  return this->nif_ > persona.nif_;
}

long Persona::operator[](int index) const
{
  return (this->nif_.getNumber() / static_cast<int>(std::pow(10, index))) % 10;
}

long unsigned int Persona::size() const
{
  return 10;
}

std::ostream &operator<<(std::ostream &os, const Persona &persona)
{
  os << "Nombre: " << persona.getName() << ", Apellidos: " << persona.getLastName() << ", NIF: " << persona.getNIF().getNumber();
  return os;
}