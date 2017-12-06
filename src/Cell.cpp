#include "Cell.hpp"
#include "Nilp.hpp"
#include "Consp.hpp"

std::shared_ptr<Cell> Cell::cons(std::shared_ptr<Primitive> left,
				 std::shared_ptr<Primitive> right) {
  std::shared_ptr<Cell> cell(new Cell(left, right));
  return cell;
}

void Cell::setCdr(std::shared_ptr<Primitive> cdr) {
  _right = cdr;
}

void Cell::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Cell::print(std::ostream& out) const {
  out << "(";
  printList(out);
  out << ")";
}

void Cell::printList(std::ostream& out) const {
  out << *_left;
  auto atom = _right;
  Nilp nilp;
  Consp consp;
  atom->accept(&nilp);

  while (!nilp.isNil()) {
    consp.reset();
    atom->accept(&consp);
    if (consp.isCell()) {
      Cell* cell = static_cast<Cell*>(atom.get());
      out << " ";
      cell->printList(out);
      break;
    } else {
      out << " . ";
      out << atom;
      break;
    }
    nilp.reset();
    atom->accept(&nilp);
  }
  _right->accept(&consp);
}


Cell::Cell(std::shared_ptr<Primitive> left,
	   std::shared_ptr<Primitive> right)
  : _left(left),
    _right(right) {}

