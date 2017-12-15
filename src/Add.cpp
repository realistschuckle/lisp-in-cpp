#include "Add.hpp"

int Add::reduce(int acc, int value) {
  return acc + value;
}

std::string Add::getName() const noexcept {
  return "+";
}
