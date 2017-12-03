#include "Symbol.hpp"

std::shared_ptr<Symbol> Symbol::make(std::string value) {
  if (Symbol::_symbols.find(value) == Symbol::_symbols.end()) {
    std::shared_ptr<Symbol> atom(new Symbol(value));
    Symbol::_symbols[value] = atom;
  }
  return Symbol::_symbols[value];
}

size_t Symbol::numberOfSymbols() {
  return Symbol::_symbols.size();
}

void Symbol::accept(PrimitiveVisitor* visitor) {
  visitor->visit(this);
}

void Symbol::print(std::ostream& out) const {
  out << "Symbol{" << _value << "}";
}

SymbolMap Symbol::_symbols;

Symbol::Symbol(std::string value) : _value(value) {}
