#include "Primitive.hpp"

std::ostream& operator<<(std::ostream& out, const Primitive& p) {
  p.print(out);
  return out;
}
