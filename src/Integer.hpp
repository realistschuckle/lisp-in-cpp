#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <iostream>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

class Integer : public Primitive {
public:
  Integer(int value) : _value(value) {}
  inline int getValue() const { return _value; }
  
  virtual void accept(PrimitiveVisitor* visitor);

protected:
  virtual void print(std::ostream& out) const;

private:
  int _value;
};

#endif
