#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "Token.hpp"

class Lexer {
public:
  Lexer(std::string input);
  Token next();

private:
  bool isWhitespace() const;
  bool isSymbolly() const;
  
  std::string _input;
  int _start;
  int _end;
};

#endif
