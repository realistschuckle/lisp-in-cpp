#ifndef NIL_HPP
#define NIL_HPP

#include <iostream>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

class Nil : public Primitive {
public:
  void accept(PrimitiveVisitor* visitor);

protected:
  void print(std::ostream& out) const;
};

#endif
