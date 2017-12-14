#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <string>
#include "Primitive.hpp"
#include "Cell.hpp"
#include "PrimitiveVisitor.hpp"
#include "Environment.hpp"

class Function : public Primitive {
public:
  virtual Primitive* exec(Cell* args) = 0;
  virtual std::string getName() const noexcept = 0;

  virtual void accept(PrimitiveVisitor* visitor);

protected:
  virtual void print(std::ostream& out) const;
};

#endif
