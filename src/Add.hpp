#ifndef ADD_HPP
#define ADD_HPP

#include <string>
#include "Math.hpp"

class Add : public Math {
public:
  virtual std::string getName() const noexcept;

protected:
  virtual int reduce(int acc, int value);
};

#endif
