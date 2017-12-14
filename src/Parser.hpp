#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include "Lexer.hpp"
#include "Primitive.hpp"

class Parser {
public:
  Parser(std::string input);
  Primitive* parse();

private:
  Primitive* parse(Token& token);
  Primitive* parseLiteral(Token& token);
  Primitive* parseList();
  Lexer _lexer;
};

#endif
