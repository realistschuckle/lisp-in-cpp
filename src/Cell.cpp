#include "Cell.hpp"
#include "Nilp.hpp"
#include "Consp.hpp"

void Cell::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Cell::print(std::ostream& out) const {
  out << "(" << *_car;
  printList(out);
  out << ")";
}

void Cell::printList(std::ostream& out) const {
  Primitive* rest = _cdr;
  Nilp nilp;
  Consp consp;
  rest->accept(&nilp);
  while (!nilp.isNil()) {
    nilp.reset();
    consp.reset();
    rest->accept(&consp);
    if (consp.isCell()) {
      out << " " << *(consp.getCell()->car());
      rest = consp.getCell()->cdr();
    } else {
      out << " . " << *rest;
      break;
    }
    rest->accept(&nilp);
  }
}
