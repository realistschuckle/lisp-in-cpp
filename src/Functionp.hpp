#ifndef FUNCTIONP_HPP
#define FUNCTIONP_HPP

#include "PrimitiveVisitor.hpp"
#include "Nil.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Cell.hpp"
#include "Function.hpp"

class Functionp : public PrimitiveVisitor {
public:
  Functionp() : _function(0) {}
  virtual void reset() { _function = 0; }
  
  virtual void visit(Nil* p)      {}
  virtual void visit(Integer* p)  {}
  virtual void visit(Symbol* p)   {}
  virtual void visit(Cell* p)     {}
  virtual void visit(Function* p) { _function = p; }

  inline bool isFunction() const { return _function != 0; }
  inline Function* getFunction() const { return _function; }

private:
  Function* _function;
};

#endif
