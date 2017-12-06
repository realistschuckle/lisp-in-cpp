#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <memory>

#include "Token.hpp"

class Lexer {
public:
  Lexer(std::string input);
  std::shared_ptr<Token> next();
  std::string getInput() const;
  
private:
  static bool isTokenCharacter(char c);
  static bool isWhitespace(char c);
  std::string _input;
  int _start;
  int _end;
};

#endif
