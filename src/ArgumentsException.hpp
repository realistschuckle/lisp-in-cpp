#ifndef ARGUMENTSEXCEPTION_HPP
#define ARGUMENTSEXCEPTION_HPP

#include <exception>
#include <string>

class ArgumentsException : std::exception {
public:
  ArgumentsException(std::string input) : _input(input) {}
  virtual const char* what() const noexcept {
    return _input.c_str();
  }

private:
  std::string _input;
};

#endif
