#ifndef NILP_HPP
#define NILP_HPP

#include "PrimitiveVisitor.hpp"

class Nilp : public PrimitiveVisitor {
public:
  Nilp() : _isNil(false) {}
  inline bool isNil() const { return _isNil; }
  
  virtual void visit(Nil* primitive) { _isNil = true; }
  virtual void visit(Integer* primitive) {}
  virtual void visit(Symbol* primitive) {}
  virtual void visit(Cell* primitive) {}

  virtual void reset() { _isNil = false; }

private:
  bool _isNil;
};

#endif
