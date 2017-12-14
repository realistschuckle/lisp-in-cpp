#ifndef UNBOUNDEXCEPTION_HPP
#define UNBOUNDEXCEPTION_HPP

#include <exception>
#include <string>

class UnboundException : std::exception {
public:
  UnboundException(std::string key) : _key(key) {}
  virtual const char* what() const noexcept {
    return _key.c_str();
  }

private:
  std::string _key;
};

#endif
