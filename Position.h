
class Position {
 public:
  Position(int index) : index_(index) {}
  int GetIndex() const { return index_; }
 private:
  int index_;
};