#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include "TokenType.hpp"

class Token {
public:
  Token(TokenType type, std::string value, int start, int end);
  TokenType getType() const;
  std::string getValue() const;
  int getStart() const;
  int getEnd() const;

  friend std::ostream& operator<<(std::ostream& out, const Token& token);
private:
  TokenType _type;
  std::string _value;
  int _start;
  int _end;
};

#endif
