#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <vector>

template <class Key>
class Sequence {
 public:
  virtual bool Search(const Key&) const = 0;
  virtual bool Insert(const Key&) = 0;
  virtual ~Sequence() = default;
  virtual Key operator[](const unsigned) const = 0;
  virtual Key& operator[](const unsigned) = 0;
};

#endif