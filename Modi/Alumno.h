#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <string>
#include "ALU.h"

class Alumno
{
public:
  Alumno() : nombre_(""), apellidos_(""), alu_(ALU()) {}
  Alumno(std::string nombre, std::string apellidos, ALU alu)
      : nombre_(nombre), apellidos_(apellidos), alu_(alu) {}
  ALU getALU() const { return alu_; }
  std::string getName() const { return nombre_; }
  std::string getLastName() const { return apellidos_; }
  bool operator==(const Alumno &) const;
  bool operator!=(const Alumno &) const;
  bool operator<(const Alumno &) const;
  bool operator>(const Alumno &) const;
  friend std::ostream &operator<<(std::ostream &os, const Alumno &Alumno);
  bool operator>=(Alumno &Alumno) const
  {
    return !(*this < Alumno);
  }
  long operator[](int) const;
  long unsigned int size() const;

private:
  std::string nombre_;
  std::string apellidos_;
  ALU alu_;
};

#endif