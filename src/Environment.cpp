#include <iostream>
#include "Environment.hpp"
#include "Add.hpp"
#include "Car.hpp"
#include "Cdr.hpp"
#include "Cons.hpp"
#include "Divide.hpp"
#include "Multiply.hpp"
#include "Subtract.hpp"
#include "UnboundException.hpp"

Environment::Environment() : _parent(0) {
  Function* builtins[] = {
    new Car(),
    new Cdr(),
    new Cons(),
    new Add(),
    new Subtract(),
    new Multiply(),
    new Divide()
  };
  for (auto builtin : builtins) {
    _values[builtin->getName()] = builtin;
  }
}

Environment::Environment(Environment* parent)
  : _parent(parent) {}

bool Environment::has(Symbol* symbol) const {
  std::string key = symbol->getValue();
  if (_values.find(key) != _values.end()) {
    return true;
  }
  return _parent && _parent->has(symbol);
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

std::ostream& operator<<(std::ostream& out, const Environment& env) {
  out << "ENVIRONMENT"
      << std::endl;
  for (auto it = env._values.begin(); it != env._values.end(); ++it) {
    out << "\t"
	<< it->first
	<< ": "
	<< *(it->second)
	<< std::endl;
  }
  if (env._parent) {
    out << *(env._parent);
  }
  return out;
}
