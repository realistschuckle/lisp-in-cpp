#ifndef EQ_HPP
#define EQ_HPP

#include <string>
#include "Function.hpp"
#include "Consp.hpp"
#include "Nilp.hpp"

class Eq : public Function {
public:
  virtual Primitive* exec(Cell* args);
  virtual std::string getName() const noexcept;

private:
  Consp _consp;
  Nilp _nilp;
};

#endif
