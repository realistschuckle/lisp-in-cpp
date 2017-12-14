#include "Cdr.hpp"
#include "Evaluator.hpp"
#include "ArgumentsException.hpp"

Primitive* Cdr::exec(Cell* args) {
  Primitive* car = args->car();
  _nilp.reset();
  car->accept(&_nilp);
  if (_nilp.isNil()) {
    return car;
  }
  _consp.reset();
  car->accept(&_consp);
  if (_consp.isCell()) {
    return _consp.getCell()->cdr();
  }
  throw ArgumentsException(args->toString());
}

std::string Cdr::getName() const noexcept {
  return "CDR";
}
