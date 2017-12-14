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
  
  virtual void visit(Nil* p)     {}
  virtual void visit(Integer* p) {}
  virtual void visit(Symbol* p)  {}
  virtual void visit(Cell* p)    {
    Consp consp;
    Nilp nilp;
    Cell* cell = p;
    Primitive* right;

    while (true) {
      consp.reset();
      right = cell->cdr();
      right->accept(&consp);
      if (consp.isCell()) {
	cell = consp.getCell();
      } else {
	break;
      }
    }

    right->accept(&nilp);
    _isList = nilp.isNil();
  }

private:
  bool _isList;
};

#endif
