#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <iostream>
#include <memory>
#include "Primitive.hpp"
#include "PrimitiveVisitor.hpp"

class Integer : public Primitive {
public:
  static std::shared_ptr<Integer> make(int value);
  virtual void accept(PrimitiveVisitor* visitor);

protected:
  virtual void print(std::ostream& out) const;

private:
  Integer(int value);
  int _value;
};

#endif
