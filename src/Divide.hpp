#ifndef DIVIDE_HPP
#define DIVIDE_HPP

#include <string>
#include "Math.hpp"

class Divide : public Math {
public:
  virtual std::string getName() const noexcept;

protected:
  virtual int reduce(int acc, int value);
};

#endif
