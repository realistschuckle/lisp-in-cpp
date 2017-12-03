#include "Primitive.hpp"

std::ostream& operator<<(std::ostream& out, const Primitive& primitive) {
  primitive.print(out);
  return out;
}

std::ostream& operator<<(std::ostream& out, const Primitive* primitive) {
  if (primitive != NULL) {
    primitive->print(out);
  }
  return out;
}
