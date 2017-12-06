#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>

#include "Lexer.hpp"
#include "Primitive.hpp"

class Parser {
public:
  Parser(Lexer& lexer);
  std::shared_ptr<Primitive> parse();
  std::string getInput() const;

private:
  std::shared_ptr<Primitive> readExpression(std::shared_ptr<Token> token);
  std::shared_ptr<Primitive> readList();
  std::shared_ptr<Primitive> readPrimitive(std::shared_ptr<Token> token);
  Lexer& _lexer;
};

#endif
