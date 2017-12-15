#include "Math.hpp"
#include "Integer.hpp"
#include "ArgumentsException.hpp"

Primitive* Math::exec(Cell* args) {
  bool first = true;
  int sum = 0;

  _consp.reset();
  _nilp.reset();
  Primitive* list = args;
  list->accept(&_consp);
  list->accept(&_nilp);
  while (_consp.isCell() && !_nilp.isNil()) {
    Primitive* left = _consp.getCell()->car();
    _numberp.reset();
    left->accept(&_numberp);
    if (_numberp.isNumber()) {
      if (first) {
	sum = _numberp.getValue();
	first = false;
      } else {
	sum = reduce(sum, _numberp.getValue());
      }
    } else {
      throw ArgumentsException(left->toString());
    }
    list = _consp.getCell()->cdr();
    _consp.reset();
    _nilp.reset();
    list->accept(&_consp);
    list->accept(&_nilp);
  }

  return new Integer(sum);
}
