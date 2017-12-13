#ifndef CONSP_HPP
#define CONSP_HPP

#include "PrimitiveVisitor.hpp"
#include "Nil.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Cell.hpp"

class Consp : public PrimitiveVisitor {
public:
  Consp() : _cell(0) {}
  virtual void reset() { _cell = 0; }
  
  virtual void visit(Nil* p)     {}
  virtual void visit(Integer* p) {}
  virtual void visit(Symbol* p)  {}
  virtual void visit(Cell* p)    { _cell = p; }

  inline bool isCell() const { return _cell != 0; }
  inline Cell* getCell() const { return _cell; }

private:
  Cell* _cell;
};

#endif
