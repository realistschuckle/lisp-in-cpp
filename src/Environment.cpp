#include "Environment.hpp"
#include "Symbolp.hpp"
#include "EvaluationException.hpp"

std::shared_ptr<Environment> Environment::global() {
  return Environment::_global;
}

std::shared_ptr<Environment> Environment::make(std::shared_ptr<Environment> parent) {
  std::shared_ptr<Environment> env(parent);
  return env;
}

std::shared_ptr<Primitive> Environment::get(std::shared_ptr<Primitive> symbol) {
  Symbolp symbolp;
  symbol->accept(&symbolp);
  if (symbolp.isSymbol()) {
    if (_dict.find(symbol) != _dict.end()) {
      return _dict[symbol];
    }
    if (this != Environment::_global.get()) {
      return _parent->get(symbol);
    }
  }
  throw new EvaluationException("Symbol not bound", symbol);
}

void Environment::set(std::shared_ptr<Primitive> symbol, std::shared_ptr<Primitive> value) {
  Symbolp symbolp;
  symbol->accept(&symbolp);
  if (symbolp.isSymbol()) {
    _dict[symbol] = value;
  }  
}

Environment::Environment(std::shared_ptr<Environment> parent)
  : _parent(parent) {}

Environment::Environment() {}

std::shared_ptr<Environment> Environment::_global(new Environment());
