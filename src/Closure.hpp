#ifndef CLOSURE_HPP
#define CLOSURE_HPP

#include <iostream>
#include "Environment.hpp"
#include "Primitive.hpp"
#include "Cell.hpp"

class Closure : public Primitive {
public:
  Closure(bool isMacro, Environment* env, Cell* arglist, Primitive* body);
  Primitive* evaluate(Cell* args);
  inline bool isMacro() { return _isMacro; }
  
  virtual void accept(PrimitiveVisitor* visitor);

protected:
  virtual void print(std::ostream& out) const;

private:
  void fillEnvironment(Environment* env, Cell* args);
  Environment* _parent;
  Cell* _arglist;
  Primitive* _body;
  bool _isMacro;
};

#endif
