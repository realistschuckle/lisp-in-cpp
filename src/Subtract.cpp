#include "Subtract.hpp"

int Subtract::reduce(int acc, int value) {
  return acc - value;
}

std::string Subtract::getName() const noexcept {
  return "-";
}
