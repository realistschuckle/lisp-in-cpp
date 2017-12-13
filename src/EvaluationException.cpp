#include "EvaluationException.hpp"

#include <iostream>
#include <sstream>

EvaluationException::EvaluationException(std::string message, std::shared_ptr<Primitive> symbol)
  : _message(message) {
  std::stringstream ss;
  ss << *symbol;
  _symbol = ss.str();
}

std::ostream& operator<<(std::ostream& out, const EvaluationException& ee) {
  out << "EVALUATION EXCEPTION: "
      << ee.getMessage()
      << " "
      << ee.getSymbol();
  return out;
}
