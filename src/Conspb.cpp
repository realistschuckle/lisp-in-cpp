#include "Conspb.hpp"
#include "Symbol.hpp"
#include "Nil.hpp"
#include "Consp.hpp"
#include "Numberp.hpp"

Primitive* Conspb::exec(Cell* args) {
  _consp.reset();
  _nilp.reset();

  args->car()->accept(&_consp);
  args->car()->accept(&_nilp);

  if (_consp.isCell() && !_nilp.isNil()) {
    return Symbol::make("T");
  }
  return Nil::make();
}

std::string Conspb::getName() const noexcept {
  return "CONSP";
}
