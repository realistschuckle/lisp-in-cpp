#include "Symbol.hpp"

void Symbol::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Symbol::print(std::ostream& out) const {
  out << _value;
}

Symbol* Symbol::make(std::string value) {
  if (Symbol::_symbols.find(value) == Symbol::_symbols.end()) {
    Symbol::_symbols[value] = new Symbol(value);
  }
  return Symbol::_symbols[value];
}

int Symbol::count() {
  return Symbol::_symbols.size();
}

std::map<std::string, Symbol*> Symbol::_symbols;
