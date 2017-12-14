#ifndef PARSEEXCEPTION_HPP
#define PARSEEXCEPTION_HPP

#include <exception>
#include <string>

class ParseException : std::exception {
public:
  ParseException(std::string message) : _message(message) {}
  virtual const char* what() const noexcept {
    return _message.c_str();
  }

private:
  std::string _message;
};

#endif
