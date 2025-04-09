#include "ALU.h"

ALU::ALU() : alu_number_(0) {}

ALU::ALU(const std::string &alu_str)
{
  if (alu_str.length() != 9)
  {
    throw std::invalid_argument("Invalid ALU length");
  }
  alu_number_ = 0;
  for (int i = 0; i < 8; ++i)
  {
    if (alu_str[i] < '0' || alu_str[i] > '9')
    {
      throw std::invalid_argument("Invalid digit in ALU");
    }
    alu_number_ = alu_number_ * 10 + (alu_str[i] - '0');
  }
  if (alu_str[8] < 'A' || alu_str[8] > 'Z')
  {
    throw std::invalid_argument("Invalid letter in ALU");
  }
  alu_number_ = alu_number_ * 100 + static_cast<int>(alu_str[8]);
}

long ALU::getNumber() const
{
  return alu_number_;
}

bool ALU::operator==(const ALU &number) const
{
  return this->alu_number_ == number.alu_number_;
}

bool ALU::operator!=(const ALU &number) const
{
  return !(*this == number);
}

bool ALU::operator<(const ALU &number) const
{
  return this->alu_number_ < number.alu_number_;
}

bool ALU::operator>(const ALU &number) const
{
  return this->alu_number_ > number.alu_number_;
}

long ALU::operator[](int index) const
{
  return (this->alu_number_ / static_cast<int>(std::pow(10, index))) % 10;
}

long unsigned int ALU::size() const
{
  return 10;
}

ALU::operator long() const
{
  return this->alu_number_;
}

std::istream &operator>>(std::istream &is, ALU &alu)
{
  std::string input;
  is >> input;
  alu = ALU(input);
  return is;
}