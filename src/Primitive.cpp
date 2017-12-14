#include <sstream>
#include "Primitive.hpp"

std::string Primitive::toString() const {
  std::stringstream stream;
  stream << *this;
  return stream.str();
}

std::ostream& operator<<(std::ostream& out, const Primitive& p) {
  p.print(out);
  return out;
}
