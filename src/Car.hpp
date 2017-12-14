#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include "Function.hpp"
#include "Consp.hpp"
#include "Environment.hpp"
#include "Cell.hpp"
#include "Nilp.hpp"

class Car : public Function {
public:
  virtual Primitive* exec(Cell* args);
  virtual std::string getName() const noexcept;

private:
  Consp _consp;
  Nilp _nilp;
};

#endif
