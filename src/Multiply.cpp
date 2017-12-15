#include "Multiply.hpp"

int Multiply::reduce(int acc, int value) {
  return acc * value;
}

std::string Multiply::getName() const noexcept {
  return "*";
}
