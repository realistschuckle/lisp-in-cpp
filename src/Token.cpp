#include <iostream>
#include "Token.hpp"

Token::Token(TokenType type, std::string input, int start, int end)
  : _type(type),
    _input(input),
    _start(start),
    _end(end) {}

std::string Token::getDesc() const {
  switch(_type) {
  case TOKEN_TICK:
    return "'";
    
  case TOKEN_EOF:
    return "EOF";
      
  case TOKEN_NIL:
    return "NIL";
      
  case TOKEN_DOT:
    return "DOT";
      
  case TOKEN_SYMBOL:
    return "SYM";
    
  case TOKEN_NUMBER:
    return "INT";
      
  case TOKEN_OPEN_PAREN:
    return "OPA";
      
  case TOKEN_CLOSE_PAREN:
    return "CPA";
  }
}

std::string Token::getValue() const {
  switch(_type) {
  case TOKEN_TICK:
    return "'";
    
  case TOKEN_EOF:
    return "";
      
  case TOKEN_NIL:
    return "NIL";
      
  case TOKEN_DOT:
    return ".";
      
  case TOKEN_SYMBOL:
  case TOKEN_NUMBER:
    return _input.substr(_start, _end - _start);
      
  case TOKEN_OPEN_PAREN:
    return "(";
      
  case TOKEN_CLOSE_PAREN:
    return ")";
  }
}

std::ostream& operator<<(std::ostream& out, const Token& token) {
  out << token.getDesc() << "<" << token.getValue() << ">";
  return out;
}
