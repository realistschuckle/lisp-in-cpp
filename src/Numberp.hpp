#ifndef NUMBERP_HPP
#define NUMBERP_HPP

#include "PrimitiveVisitor.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Cell.hpp"

class Numberp : public PrimitiveVisitor {
public:
  Numberp() : _isNumber(0) {}
  inline bool isNumber() const { return _isNumber; }
  inline int getValue() const { return _value; }
  
  virtual void reset() { _isNumber = false; _value = 0; }
  
  virtual void visit(Nil* p)      {}
  virtual void visit(Symbol* p)   {}
  virtual void visit(Cell* p)     {}
  virtual void visit(Function* p) {}
  virtual void visit(Integer* p)  {
    _isNumber = true;
    _value = p->getValue();
  }

private:
  bool _isNumber;
  int _value;
};

#endif
