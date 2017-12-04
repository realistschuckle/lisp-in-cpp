#include "Integer.hpp"

std::shared_ptr<Integer> Integer::make(int value) {
  std::shared_ptr<Integer> integer(new Integer(value));
  return integer;
}

void Integer::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Integer::print(std::ostream& out) const {
  out << _value;
}

Integer::Integer(int value) : _value(value) {}
