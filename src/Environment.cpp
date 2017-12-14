#include "Environment.hpp"
#include "Car.hpp"
#include "Cdr.hpp"
#include "Cons.hpp"
#include "UnboundException.hpp"

Environment::Environment() : _parent(0) {
  Function* builtins[] = { new Car(), new Cdr(), new Cons() };
  for (auto builtin : builtins) {
    _values[builtin->getName()] = builtin;
  }
}

Environment::Environment(Environment* parent)
  : _parent(parent) {}

bool Environment::has(Symbol* symbol) const {
  std::string key = symbol->getValue();
  return _values.find(key) != _values.end();
}

Primitive* Environment::get(Symbol* symbol) const {
  std::string key = symbol->getValue();
  auto search = _values.find(key);
  if (search != _values.end()) {
    return search->second;
  }
  if (_parent != 0) {
    return _parent->get(symbol);
  }
  throw UnboundException(key);
}

void Environment::set(Symbol* symbol, Primitive* value) {
  std::string key = symbol->getValue();
  _values[key] = value;
}
