#ifndef SORT_METHOD_H
#define SORT_METHOD_H

template <class key>
class SortMethod {
public:
  SortMethod(staticSequence<Key>, size);
  ~SortMethod();
  virtual void Sort() const = 0;
};

#endif