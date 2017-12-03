#ifndef PRIMITIVEVISITOR_HPP
#define PRIMITIVEVISITOR_HPP

class Nil;
class Integer;
class Symbol;
class Cell;

class PrimitiveVisitor {
public:
  virtual void visit(Nil* primitive) = 0;
  virtual void visit(Integer* primitive) = 0;
  virtual void visit(Symbol* primitive) = 0;
  virtual void visit(Cell* primitive) = 0;

  virtual void reset() = 0;
};

#endif
