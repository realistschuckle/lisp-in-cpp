#ifndef NIL_HPP
#define NIL_HPP

#include <iostream>
#include "Cell.hpp"
#include "PrimitiveVisitor.hpp"

class Nil : public Cell {
public:
  static Nil* make();
  void accept(PrimitiveVisitor* visitor);

protected:
  void print(std::ostream& out) const;

private:
  static Nil* _global;
  Nil();
};

#endif
