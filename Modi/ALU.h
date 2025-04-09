#ifndef ALU_H_
#define ALU_H_

#include <iostream>
#include <iostream>
#include <stdexcept>
#include <cmath>

class ALU
{
public:
  ALU();
  ALU(const std::string &alu_str);

  long getNumber() const;

  long operator[](int) const;
  bool operator==(const ALU &) const;
  bool operator!=(const ALU &) const;
  bool operator<(const ALU &) const;
  bool operator>(const ALU &) const;
  long unsigned int size() const;

  operator long() const;

  friend std::istream &operator>>(std::istream &is, ALU &alu);

private:
  long alu_number_;
};

#endif