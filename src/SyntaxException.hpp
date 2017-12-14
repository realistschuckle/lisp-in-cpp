#ifndef SYNTAXEXCEPTION_HPP
#define SYNTAXEXCEPTION_HPP

#include <exception>
#include <string>

class SyntaxException : std::exception {
public:
  SyntaxException(std::string input) : _input(input) {}
  virtual const char* what() const noexcept {
    return _input.c_str();
  }

private:
  std::string _input;
};

#endif
