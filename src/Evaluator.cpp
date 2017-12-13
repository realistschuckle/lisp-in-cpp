#include "Evaluator.hpp"
#include "EvaluationException.hpp"
#include "Listp.hpp"
#include "Symbolp.hpp"
#include "Consp.hpp"

Evaluator::Evaluator(std::shared_ptr<Environment> environment)
  : _env(environment), _result(nullptr) {}

void Evaluator::visit(Nil* primitive) {
  _result = primitive;
}

void Evaluator::visit(Integer* primitive) {
  _result = primitive;
}

void Evaluator::visit(Symbol* primitive) {
  std::shared_ptr<Primitive> symbol(primitive, noDelete);
  _result = _env->get(symbol).get();
}

void Evaluator::visit(Cell* primitive) {
  Listp listp;
  primitive->accept(&listp);
  if (!listp.isList()) {
    std::shared_ptr<Primitive> symbol(primitive, noDelete);
    throw new EvaluationException("Not a proper list", symbol);
  }
  std::shared_ptr<Primitive> car = primitive->car();
  std::shared_ptr<Primitive> cdr = primitive->cdr();

  Symbolp symbolp;
  car->accept(&symbolp);

  Nilp nilp;
  if (symbolp.isSymbol() && symbolp.getValue() == "QUOTE") {
    cdr->accept(&nilp);
    if (nilp.isNil()) {
      std::shared_ptr<Primitive> symbol(primitive, noDelete);
      throw new EvaluationException("Not enough arguments", symbol);
    }
    _result = cdr.get();
  }
  if (symbolp.isSymbol() && symbolp.getValue() == "DEFINE") {
    Consp consp;
    cdr->accept(&consp);
    if (!consp.isCell()) {
      std::shared_ptr<Primitive> symbol(primitive, noDelete);
      throw new EvaluationException("Not enough arguments", symbol);
    }
    Cell* cell = static_cast<Cell*>(cdr.get());
    std::shared_ptr<Primitive> name = cell->car();
    std::shared_ptr<Primitive> value = cell->cdr();

    symbolp.reset();
    name->accept(&symbolp);
    if (!symbolp.isSymbol()) {
      std::shared_ptr<Primitive> symbol(primitive, noDelete);
      throw new EvaluationException("Not a symbol for define first argument", symbol);
    }

    Evaluator eval(_env);
    value->accept(&eval);
    _result = name.get();
    std::shared_ptr<Primitive> stored(eval.getResult());
    _env->set(name, stored);
  }

  if (!symbolp.isSymbol()) {
    std::shared_ptr<Primitive> symbol(primitive, noDelete);
    throw new EvaluationException("car is not a symbol", symbol);
  }

}

void Evaluator::reset() {
  _result = nullptr;
}

void Evaluator::noDelete(Primitive* p) {}
