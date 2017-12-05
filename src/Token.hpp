#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include "TokenType.hpp"

class Token {
public:
  Token(TokenType type, std::string value);
  TokenType getType() const;
  std::string getValue() const;

  friend std::ostream& operator<<(std::ostream& out, const Token& token);
private:
  TokenType _type;
  std::string _value;
};

#endif
