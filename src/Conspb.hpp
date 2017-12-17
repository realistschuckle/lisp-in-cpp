#ifndef CONSPB_HPP
#define CONSPB_HPP

#include <string>
#include "Function.hpp"
#include "Consp.hpp"
#include "Nilp.hpp"

class Conspb : public Function {
public:
  virtual Primitive* exec(Cell* args);
  virtual std::string getName() const noexcept;

private:
  Consp _consp;
  Nilp _nilp;
};

#endif
