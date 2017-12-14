#ifndef SYMBOLP_HPP
#define SYMBOLP_HPP

#include "PrimitiveVisitor.hpp"
#include "Nil.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Cell.hpp"
#include "Consp.hpp"
#include "Nilp.hpp"

class Symbolp : public PrimitiveVisitor {
public:
  Symbolp() : _symbol(0) {}
  inline bool isSymbol() const { return _symbol != 0; }
  inline Symbol* getSymbol() const { return _symbol; }
  
  virtual void reset() { _symbol = 0; }
  
  virtual void visit(Nil* p)     {}
  virtual void visit(Integer* p) {}
  virtual void visit(Symbol* p)  { _symbol = p; }
  virtual void visit(Cell* p)    {}

private:
  Symbol* _symbol;
};

#endif
