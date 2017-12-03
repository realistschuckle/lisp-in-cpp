#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <iostream>
#include "PrimitiveVisitor.hpp"

class Primitive {
public:
  virtual void accept(PrimitiveVisitor* visitor) = 0;
  friend std::ostream& operator<<(std::ostream& out, const Primitive& primitive);
  friend std::ostream& operator<<(std::ostream& out, const Primitive* primitive);

protected:
  virtual void print(std::ostream& out) const = 0;
};

#endif
