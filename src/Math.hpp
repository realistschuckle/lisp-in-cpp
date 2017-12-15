#ifndef MATH_HPP
#define MATH_HPP

#include <string>
#include "Function.hpp"
#include "Consp.hpp"
#include "Numberp.hpp"
#include "Cell.hpp"
#include "Nilp.hpp"

class Math : public Function {
public:
  virtual Primitive* exec(Cell* args);
  virtual std::string getName() const noexcept = 0;

protected:
  virtual int reduce(int acc, int value) = 0;
  
private:
  Consp _consp;
  Nilp _nilp;
  Numberp _numberp;
};

#endif
