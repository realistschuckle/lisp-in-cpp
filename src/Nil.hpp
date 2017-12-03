#ifndef NIL_HPP
#define NIL_HPP

#include <iostream>
#include <memory>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

class Nil : public Primitive {
public:
  static std::shared_ptr<Nil> make();
  virtual void accept(PrimitiveVisitor* visitor);

protected:
  virtual void print(std::ostream& out) const;

private:
  static std::shared_ptr<Nil> _instance;
  Nil();
};

#endif
