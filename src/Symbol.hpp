#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <map>
#include <iostream>
#include <string>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

class Symbol : public Primitive {
public:
  static Symbol* make(std::string value);
  static int count();
  inline std::string getValue() const { return _value; }

  virtual void accept(PrimitiveVisitor* visitor);

protected:
  virtual void print(std::ostream& out) const;

private:
  Symbol(std::string value) : _value(value) {}
  std::string _value;
  static std::map<std::string, Symbol*> _symbols;
};

#endif
