#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

typedef std::map<std::string, std::shared_ptr<Symbol> > SymbolMap;

class Symbol : public Primitive {
public:
  static std::shared_ptr<Symbol> make(std::string value);
  static size_t numberOfSymbols();
  virtual void accept(PrimitiveVisitor* visitor);

protected:
  virtual void print(std::ostream& out) const;

private:
  static SymbolMap _symbols;
  Symbol(std::string value);
  std::string _value;
};

#endif
