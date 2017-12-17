#ifndef LISTP_HPP
#define LISTP_HPP

#include "PrimitiveVisitor.hpp"
#include "Nil.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Cell.hpp"
#include "Consp.hpp"
#include "Nilp.hpp"

class Listp : public PrimitiveVisitor {
public:
  Listp() : _isList(false) {}
  inline bool isList() const { return _isList; }
  
  virtual void reset() { _isList = false; }
  
  virtual void visit(Nil* p)      { _isList = true; }
  virtual void visit(Integer* p)  {}
  virtual void visit(Symbol* p)   {}
  virtual void visit(Function* p) {}
  virtual void visit(Closure* p)  {}
  virtual void visit(Cell* p)     {
    Consp consp;
    Nilp nilp;
    Cell* cell = p;
    Primitive* right;

    while (true) {
      consp.reset();
      nilp.reset();
      right = cell->cdr();
      right->accept(&consp);
      right->accept(&nilp);
      if (nilp.isNil() || !consp.isCell()) {
	break;
      } else {
	cell = consp.getCell();
      }
    }

    _isList = nilp.isNil();
  }

private:
  bool _isList;
};

#endif
