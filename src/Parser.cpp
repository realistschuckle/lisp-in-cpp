#include "Parser.hpp"
#include "ParseException.hpp"
#include "TokenType.hpp"
#include "Integer.hpp"
#include "Nil.hpp"
#include "Symbol.hpp"
#include "Nilp.hpp"
#include "Cell.hpp"

Parser::Parser(std::string input)
  : _lexer(input) {}

Primitive* Parser::parse() {
  Token token = _lexer.next();
  return parse(token);
}

Primitive* Parser::parse(Token& token) {
  if (token.getType() == TOKEN_OPEN_PAREN) {
    return parseList();
  } else if (token.getType() == TOKEN_CLOSE_PAREN) {
    throw ParseException("Unexpected close paren.");
  } else if (token.getType() == TOKEN_TICK) {
    Token next = _lexer.next();
    return new Cell(Symbol::make("QUOTE"), new Cell(parse(next), Nil::make()));
  } else if (token.getType() == TOKEN_BACKTICK) {
    Token next = _lexer.next();
    return new Cell(Symbol::make("QUASIQUOTE"), new Cell(parse(next), Nil::make()));    
  } else if (token.getType() == TOKEN_COMMA) {
    std::string type = "UNQUOTE";
    Token next = _lexer.next();
    if (next.getType() == TOKEN_AT) {
      type = "UNQUOTE-SPLICING";
      next = _lexer.next();
    }
    return new Cell(Symbol::make(type), new Cell(parse(next), Nil::make()));    
  } else {
    return parseLiteral(token);
  }
}

Primitive* Parser::parseLiteral(Token& token) {
  if (token.getType() == TOKEN_NUMBER) {
    int i = std::stoi(token.getValue());
    return new Integer(i);
  }
  if (token.getType() == TOKEN_NIL) {
    return Nil::make();
  }
  return Symbol::make(token.getValue());
}

Primitive* Parser::parseList() {
  Primitive* result = Nil::make();
  Cell* lastCell = 0;
  while (true) {
    Token t = _lexer.next();
    if (t.getType() == TOKEN_EOF) {
      throw ParseException("Unexpected end of input");
    }
    if (t.getType() == TOKEN_CLOSE_PAREN) {
      return result;
    }
    if (t.getType() == TOKEN_DOT) {
      if (lastCell == 0) {
	throw ParseException("No car for improper list.");
      }
      
      Primitive* cdr = parse();
      lastCell->setCdr(cdr);
      
      t = _lexer.next();
      if (t.getType() != TOKEN_CLOSE_PAREN) {
	throw ParseException("Missing close paren.");
      }
      return result;
    }
    Primitive* car = parse(t);
    if (lastCell == 0) {
      result = lastCell = new Cell(car, result);
    } else {
      Cell* cell = new Cell(car, Nil::make());
      lastCell->setCdr(cell);
      lastCell = cell;
    }
  }
  return 0;
}
