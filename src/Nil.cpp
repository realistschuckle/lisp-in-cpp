#include "Nil.hpp"

void Nil::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Nil::print(std::ostream& out) const {
  out << "NIL";
}
