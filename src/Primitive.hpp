#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <iostream>
#include <string>
#include "PrimitiveVisitor.hpp"

class Primitive {
public:
  virtual void accept(PrimitiveVisitor* visitor) = 0;
  std::string toString() const;

  friend std::ostream& operator<<(std::ostream& out, const Primitive& p);

protected:
  virtual void print(std::ostream& out) const = 0;  
};

#endif
