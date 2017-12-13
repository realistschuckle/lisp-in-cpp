#ifndef LISTP_HPP
#define LISTP_HPP

#include <memory>
#include "PrimitiveVisitor.hpp"
#include "Primitive.hpp"
#include "Consp.hpp"
#include "Nilp.hpp"

class Listp : public PrimitiveVisitor {
public:
  Listp() : _isList(false) {}
  inline bool isList() const { return _isList; }
  
  virtual void visit(Nil* primitive) {}
  virtual void visit(Integer* primitive) {}
  virtual void visit(Symbol* primitive) {}
  inline virtual void visit(Cell* primitive) {
    Consp consp;
    Nilp nilp;
    std::shared_ptr<Primitive> ptr = primitive->cdr();
    _isList = false;

    while (true) {
      nilp.reset();
      ptr->accept(&nilp);
      if (nilp.isNil()) {
	_isList = true;
	break;
      }
      consp.reset();
      ptr->accept(&consp);
      if (consp.isCell()) {
	ptr = static_cast<Cell*>(ptr.get())->cdr();
      } else {
	break;
      }
    }
  }

  virtual void reset() { _isList = false; }

private:
  bool _isList;
};

#endif
