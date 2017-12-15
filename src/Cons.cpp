#include "Cons.hpp"
#include "Cell.hpp"
#include "Evaluator.hpp"
#include "ArgumentsException.hpp"

Primitive* Cons::exec(Cell* args) {
  _nilp.reset();
  args->accept(&_nilp);
  if (_nilp.isNil()) {
    throw ArgumentsException(args->toString());
  }

  _consp.reset();
  args->accept(&_consp);
  if (_consp.isCell()) {
    Primitive* car = _consp.getCell()->car();
    Primitive* cdr = _consp.getCell()->cdr();
    _consp.reset();
    _nilp.reset();
    cdr->accept(&_consp);
    cdr->accept(&_nilp);
    if (_consp.isCell() && !_nilp.isNil()) {
      cdr = _consp.getCell()->car();
      return new Cell(car, cdr);
    }
  }
  throw ArgumentsException(args->toString());
}

std::string Cons::getName() const noexcept {
  return "CONS";
}
