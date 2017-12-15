#ifndef SUBTRACT_HPP
#define SUBTRACT_HPP

#include <string>
#include "Math.hpp"

class Subtract : public Math {
public:
  virtual std::string getName() const noexcept;

protected:
  virtual int reduce(int acc, int value);
};

#endif
