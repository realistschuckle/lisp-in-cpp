#include "Nil.hpp"

Nil* Nil::make() {
  return Nil::_global;
}

void Nil::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Nil::print(std::ostream& out) const {
  out << "NIL";
}

Nil::Nil() : Cell(this, this) {}

Nil* Nil::_global = new Nil();
