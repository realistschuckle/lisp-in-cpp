#ifndef CONS_HPP
#define CONS_HPP

#include <string>
#include "Function.hpp"
#include "Consp.hpp"
#include "Environment.hpp"

class Cons : public Function {
public:
  virtual Primitive* exec(Cell* args);
  virtual std::string getName() const noexcept;

private:
  Consp _consp;
};

#endif
