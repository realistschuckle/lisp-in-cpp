#include "Nil.hpp"

std::shared_ptr<Nil> Nil::make() {
  return Nil::_instance;
}

void Nil::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Nil::print(std::ostream& out) const {
  out << "Nil{}";
}

std::shared_ptr<Nil> Nil::_instance(new Nil());

Nil::Nil() {}
