#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

class Cell : public Primitive {
public:
  Cell(Primitive* car, Primitive* cdr) : _car(car), _cdr(cdr) {}
  inline Primitive* car() const { return _car; }
  inline Primitive* cdr() const { return _cdr; }
  inline void setCdr(Primitive* cdr) { _cdr = cdr; }

  virtual void accept(PrimitiveVisitor* visitor);

protected:
  virtual void print(std::ostream& out) const;

private:
  void printList(std::ostream& out) const;
  Primitive* _car;
  Primitive* _cdr;
};

#endif
