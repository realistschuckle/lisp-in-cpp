#include "Divide.hpp"

int Divide::reduce(int acc, int value) {
  return acc / value;
}

std::string Divide::getName() const noexcept {
  return "/";
}
