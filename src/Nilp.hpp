#ifndef NILP_HPP
#define NILP_HPP

#include "PrimitiveVisitor.hpp"
#include "Nil.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Cell.hpp"

class Nilp : public PrimitiveVisitor {
public:
  Nilp() : _isNil(false) {}
  inline bool isNil() const { return _isNil; }
  
  virtual void reset() { _isNil = false; }
  
  virtual void visit(Nil* p)      { _isNil = true; }
  virtual void visit(Integer* p)  {}
  virtual void visit(Symbol* p)   {}
  virtual void visit(Cell* p)     {}
  virtual void visit(Function* p) {}
  virtual void visit(Closure* p)  {}

private:
  bool _isNil;
};

#endif
