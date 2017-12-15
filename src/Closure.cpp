#include "Closure.hpp"
#include "Nilp.hpp"
#include "Consp.hpp"
#include "Symbolp.hpp"
#include "Evaluator.hpp"
#include "ArgumentsException.hpp"

Closure::Closure(Environment* env, Cell* arglist, Primitive* body)
  : _parent(env),
    _arglist(arglist),
    _body(body) {}

void Closure::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Closure::print(std::ostream& out) const {
  out << "#<LAMBDA:"
      << *_arglist
      << " "
      << *_body
      << ">";
}

Primitive* Closure::evaluate(Cell* args) {
  Environment* env = new Environment(_parent);
  fillEnvironment(env, args);

  Evaluator evaluator(env);
  return evaluator.eval(_body);
}

void Closure::fillEnvironment(Environment* env, Cell* args) {
  Cell* symbols = _arglist;
  Cell* values = args;
  
  Symbolp sym;
  Consp syms;
  Consp vals;
  Nilp snilp;
  Nilp vnilp;

  while (true) {
    snilp.reset();
    vnilp.reset();
    symbols->accept(&snilp);
    values->accept(&vnilp);
    if (snilp.isNil() && vnilp.isNil()) {
      return;
    } else if (snilp.isNil() || vnilp.isNil()) {
      throw ArgumentsException(args->toString());
    }
    
    sym.reset();
    symbols->car()->accept(&sym);
    env->set(sym.getSymbol(), args->car());

    syms.reset();
    vals.reset();
    symbols->cdr()->accept(&syms);
    values->cdr()->accept(&vals);
    symbols = syms.getCell();
    values = vals.getCell();
  }
}
