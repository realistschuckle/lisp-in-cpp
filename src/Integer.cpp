#include "Integer.hpp"

void Integer::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Integer::print(std::ostream& out) const {
  out << _value;
}
