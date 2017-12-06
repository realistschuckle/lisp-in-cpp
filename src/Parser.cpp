#include "Parser.hpp"
#include "Nilp.hpp"
#include "ParseException.hpp"
#include "Token.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Nil.hpp"
#include "Cell.hpp"

Parser::Parser(Lexer& lexer)
  : _lexer(lexer) {}

std::shared_ptr<Primitive> Parser::parse() {
  auto token = _lexer.next();
  return readExpression(token);
}

std::string Parser::getInput() const {
  return _lexer.getInput();
}

std::shared_ptr<Primitive> Parser::readExpression(std::shared_ptr<Token> token) {
  switch (token->getType()) {
  case TOKEN_OPEN_PAREN:
    return readList();
  case TOKEN_CLOSE_PAREN:
    throw new ParseException("Unexpected ')'", getInput(), token->getStart(), token->getEnd());
  default:
    return readPrimitive(token);
  }
}

std::shared_ptr<Primitive> Parser::readList() {
  Nilp nilp;
  std::shared_ptr<Primitive> result = Nil::make();
  std::shared_ptr<Primitive> item;
  std::shared_ptr<Cell> lastCell;
  while (true) {
    auto token = _lexer.next();
    
    if (token->getType() == TOKEN_CLOSE_PAREN) {
      break;
    }

    if (token->getType() == TOKEN_DOT) {
      nilp.reset();
      result->accept(&nilp);
      if (nilp.isNil()) {
	throw new ParseException("Misplaced dot.",
				 getInput(),
				 token->getStart(),
				 token->getEnd());
      }

      item = readExpression(_lexer.next());
      token = _lexer.next();
      if (token->getType() != TOKEN_CLOSE_PAREN) {
	throw new ParseException("Expected )",
				 getInput(),
				 token->getStart(),
				 token->getEnd());
      }
      lastCell->setCdr(item);
      break;
    }

    item = readExpression(token);
    nilp.reset();
    result->accept(&nilp);
    if (nilp.isNil()) {
      result = lastCell = Cell::cons(item, Nil::make());
    } else {
      std::shared_ptr<Cell> cdr = Cell::cons(item, Nil::make());
      lastCell->setCdr(cdr);
      lastCell = cdr;
    }
  }
  
  return result;
}

std::shared_ptr<Primitive> Parser::readPrimitive(std::shared_ptr<Token> token) {
  std::string value = token->getValue();
  try {
    int i = std::stoi(value);
    return Integer::make(i);
  } catch(std::invalid_argument ia) {
  }
  if (value == "NIL") {
    return Nil::make();
  }
  return Symbol::make(value);
}
