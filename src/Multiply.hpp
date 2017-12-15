#ifndef MULTIPLY_HPP
#define MULTIPLY_HPP

#include <string>
#include "Math.hpp"

class Multiply : public Math {
public:
  virtual std::string getName() const noexcept;

protected:
  virtual int reduce(int acc, int value);
};

#endif
