#include "Token.hpp"

Token::Token(TokenType type, std::string value, int start, int end)
  : _type(type),
    _value(value),
    _start(start),
    _end(end) {}

TokenType Token::getType() const {
  return _type;
}

std::string Token::getValue() const {
  return _value;
}

int Token::getStart() const {
  return _start;
}

int Token::getEnd() const {
  return _end;
}

std::ostream& operator<<(std::ostream& out, const Token& token) {
  out << "Token{" << token._value << "}";
  return out;
}
