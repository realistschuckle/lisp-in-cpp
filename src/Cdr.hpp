#ifndef CDR_HPP
#define CDR_HPP

#include <string>
#include "Function.hpp"
#include "Consp.hpp"
#include "Environment.hpp"
#include "Cell.hpp"

class Cdr : public Function {
public:
  virtual Primitive* exec(Cell* args);
  virtual std::string getName() const noexcept;

private:
  Consp _consp;
};

#endif
