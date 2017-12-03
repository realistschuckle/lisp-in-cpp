#ifndef CONSP_HPP
#define CONSP_HPP

#include "PrimitiveVisitor.hpp"

class Consp : public PrimitiveVisitor {
public:
  Consp() : _isCell(false) {}
  inline bool isCell() const { return _isCell; }
  
  virtual void visit(Nil* primitive) {}
  virtual void visit(Integer* primitive) {}
  virtual void visit(Symbol* primitive) {}
  inline virtual void visit(Cell* primitive) { _isCell = true; }

  virtual void reset() { _isCell = false; }

private:
  bool _isCell;
};

#endif
