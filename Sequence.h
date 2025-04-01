#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <vector>

template <class Key>
class Sequence {
 public:
  virtual bool Search(const Key&) const = 0;
  virtual bool Insert(const Key&) = 0;
  virtual ~Sequence() = default;
  virtual Key Sequence<Key>::operator[](const Position&) const = 0;
};

#endif