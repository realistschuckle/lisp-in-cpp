#include "Car.hpp"
#include "Evaluator.hpp"
#include "ArgumentsException.hpp"

Primitive* Car::exec(Cell* args) {
  _nilp.reset();
  args->accept(&_nilp);
  if (_nilp.isNil()) {
    throw ArgumentsException(args->toString());
  }
  
  Primitive* car = args->car();
  _nilp.reset();
  car->accept(&_nilp);
  if (_nilp.isNil()) {
    return car;
  }
  _consp.reset();
  car->accept(&_consp);
  if (_consp.isCell()) {
    return _consp.getCell()->car();
  }
  throw ArgumentsException(args->toString());
}

std::string Car::getName() const noexcept {
  return "CAR";
}
