#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <memory>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

class Cell : public Primitive {
public:
  static std::shared_ptr<Cell> cons(std::shared_ptr<Primitive> left,
				    std::shared_ptr<Primitive> right);
  virtual void accept(PrimitiveVisitor* visitor);
  inline std::shared_ptr<Primitive> car() { return _left; }
  inline std::shared_ptr<Primitive> cdr() { return _right; }

protected:
  virtual void print(std::ostream& out) const;

private:
  virtual void printList(std::ostream& out) const;
  Cell(std::shared_ptr<Primitive> left,
       std::shared_ptr<Primitive> right);
  std::shared_ptr<Primitive> _left;
  std::shared_ptr<Primitive> _right;  
};

#endif
