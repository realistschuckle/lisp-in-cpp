#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include "TokenType.hpp"

class Token {
public:
  Token(TokenType type, std::string input, int start, int end);
  inline TokenType getType() const { return _type; }
  std::string getValue() const;
  std::string getDesc() const;

private:
  TokenType _type;
  std::string _input;
  int _start;
  int _end;
};

std::ostream& operator<<(std::ostream& out, const Token& token);

#endif
