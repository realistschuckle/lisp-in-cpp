#include "Eq.hpp"
#include "Symbol.hpp"
#include "Nil.hpp"
#include "Consp.hpp"
#include "Numberp.hpp"

Primitive* Eq::exec(Cell* args) {
  Numberp lnum;
  Numberp rnum;
  Consp consp;

  args->cdr()->accept(&consp);
  Primitive* left = args->car();
  Primitive* right = consp.getCell()->car();
  left->accept(&lnum);
  right->accept(&rnum);
  if (lnum.isNumber() && rnum.isNumber() && lnum.getValue() == rnum.getValue()) {
    return Symbol::make("T");
  }
  if (left == right) {
    return Symbol::make("T");
  }
  
  return Nil::make();
}

std::string Eq::getName() const noexcept {
  return "EQ";
}
