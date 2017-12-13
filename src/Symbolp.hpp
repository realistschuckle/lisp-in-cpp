#ifndef SYMBOLP_HPP
#define SYMBOLP_HPP

#include <string>
#include "PrimitiveVisitor.hpp"
#include "Symbol.hpp"

class Symbolp : public PrimitiveVisitor {
public:
  Symbolp() : _isSymbol(false) {}
  inline bool isSymbol() const { return _isSymbol; }
  inline std::string getValue() const { return _symbol; }
  
  virtual void visit(Nil* primitive) {}
  virtual void visit(Integer* primitive) {}
  virtual void visit(Symbol* primitive) {
    _isSymbol = true;
    _symbol = primitive->getValue();
  }
  inline virtual void visit(Cell* primitive) {}

  virtual void reset() { _isSymbol = false; }

private:
  bool _isSymbol;
  std::string _symbol;
};

#endif
