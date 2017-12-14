#ifndef PRIMITIVEVISITOR_HPP
#define PRIMITIVEVISITOR_HPP

class Nil;
class Integer;
class Symbol;
class Cell;
class Function;

class PrimitiveVisitor {
public:
  virtual void reset() = 0;
  
  virtual void visit(Nil* p) = 0;
  virtual void visit(Integer* p) = 0;
  virtual void visit(Symbol* p) = 0;
  virtual void visit(Cell* p) = 0;
  virtual void visit(Function* p) = 0;
};

#endif
