#ifndef EVALUATIONEXCEPTION_HPP
#define EVALUATIONEXCEPTION_HPP

#include <string>
#include "Primitive.hpp"

class EvaluationException {
public:
  EvaluationException(std::string message, std::shared_ptr<Primitive> symbol);
  
  inline std::string getSymbol() const { return _symbol; }
  inline std::string getMessage() const { return _message; }

private:
  std::string _symbol;
  std::string _message;
};

std::ostream& operator<<(std::ostream& out, const EvaluationException& pe);

#endif
