#ifndef NIL_HPP
#define NIL_HPP

#include <iostream>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

class Nil : public Primitive {
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
