#ifndef NUMBERLT_HPP
#define NUMBERLT_HPP

#include <string>
#include "Function.hpp"
#include "Consp.hpp"
#include "Numberp.hpp"
#include "Cell.hpp"
#include "Nilp.hpp"

class NumberLt : public Function {
public:
  virtual Primitive* exec(Cell* args);
  virtual std::string getName() const noexcept;

private:
  Consp _consp;
  Nilp _nilp;
  Numberp _numberp;
};

#endif
