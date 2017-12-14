#include "Environment.hpp"
#include "UnboundException.hpp"

Environment::Environment() : _parent(0) {}

Environment::Environment(Environment* parent)
  : _parent(parent) {}

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
