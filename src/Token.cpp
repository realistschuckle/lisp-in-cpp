#include "Token.hpp"

Token::Token(TokenType type, std::string value)
  : _type(type),
    _value(value) {}

TokenType Token::getType() const {
  return _type;
}

std::string Token::getValue() const {
  return _value;
}

std::ostream& operator<<(std::ostream& out, const Token& token) {
  out << "Token{" << token._value << "}";
  return out;
}
