#ifndef CLOSUREP_HPP
#define CLOSUREP_HPP

#include "PrimitiveVisitor.hpp"
#include "Nil.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Cell.hpp"
#include "Closure.hpp"

class Closurep : public PrimitiveVisitor {
public:
  Closurep() : _closure(0) {}
  virtual void reset() { _closure = 0; }
  
  virtual void visit(Nil* p)      {}
  virtual void visit(Integer* p)  {}
  virtual void visit(Symbol* p)   {}
  virtual void visit(Cell* p)     {}
  virtual void visit(Function* p) {}
  virtual void visit(Closure* p)  { _closure = p; }

  inline bool isClosure() const { return _closure != 0; }
  inline Closure* getClosure() const { return _closure; }

private:
  Closure* _closure;
};

#endif
