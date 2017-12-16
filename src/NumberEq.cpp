#include "NumberEq.hpp"
#include "Nil.hpp"
#include "Symbol.hpp"
#include "Evaluator.hpp"
#include "ArgumentsException.hpp"

Primitive* NumberEq::exec(Cell* args) {
  _nilp.reset();
  args->accept(&_nilp);
  if (_nilp.isNil()) {
    throw ArgumentsException(args->toString());
  }
  
  Primitive* car = args->car();
  _numberp.reset();
  car->accept(&_numberp);
  if (!_numberp.isNumber()) {
    throw ArgumentsException(args->toString());
  }
  int left = _numberp.getValue();
  
  _consp.reset();
  _numberp.reset();
  args->cdr()->accept(&_consp);
  if (!_consp.isCell()) {
    throw ArgumentsException(args->toString());
  }
  _consp.getCell()->car()->accept(&_numberp);
  if (!_numberp.isNumber()) {
    throw ArgumentsException(args->toString());
  }
  int right = _numberp.getValue();
  
  if (left == right) {
    return Symbol::make("T");
  }
  return Nil::make();
}

std::string NumberEq::getName() const noexcept {
  return "=";
}
