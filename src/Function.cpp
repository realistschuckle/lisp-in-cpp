#include "Function.hpp"

void Function::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Function::print(std::ostream& out) const {
  out << "#<BUILTIN:" << getName() << ">";
}
