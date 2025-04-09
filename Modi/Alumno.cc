#include "Alumno.h"

bool Alumno::operator==(const Alumno &Alumno) const
{
  return this->alu_ == Alumno.alu_;
}

bool Alumno::operator!=(const Alumno &Alumno) const
{
  return !(*this == Alumno);
}

bool Alumno::operator<(const Alumno &Alumno) const
{
  return this->alu_ < Alumno.alu_;
}

bool Alumno::operator>(const Alumno &Alumno) const
{
  return this->alu_ > Alumno.alu_;
}

long Alumno::operator[](int index) const
{
  return (this->alu_.getNumber() / static_cast<int>(std::pow(10, index))) % 10;
}

long unsigned int Alumno::size() const
{
  return 10;
}

std::ostream &operator<<(std::ostream &os, const Alumno &Alumno)
{
  os << "{ Nombre: " << Alumno.getName() << ", Apellidos: " << Alumno.getLastName() << ", ALU: " << Alumno.getALU().getNumber() << " }";
  return os;
}