#include <algorithm>
#include "Lexer.hpp"
#include "TokenType.hpp"

Lexer::Lexer(std::string input)
  : _input(input),
    _start(0),
    _end(0) {
  std::transform(_input.begin(), _input.end(), _input.begin(), ::toupper);
}

Token Lexer::next() {
  if (_end >= _input.length()) {
    Token t(TOKEN_EOF, _input, _input.size() - 1, _input.size() - 1);
    return t;
  }
  while (isWhitespace()) {
    _end += 1;
  }
  _start = _end;
  if (_input[_end] == '(') {
    _end += 1;
    Token t(TOKEN_OPEN_PAREN, _input, _start, _end);
    return t;
  }
  if (_input[_end] == ')') {
    _end += 1;
    Token t(TOKEN_CLOSE_PAREN, _input, _start, _end);
    return t;
  }
  if (_input[_end] == '.') {
    _end += 1;
    Token t(TOKEN_DOT, _input, _start, _end);
    return t;
  }
  while (isSymbolly()) {
    _end += 1;
  }
  std::string symbol = _input.substr(_start, _end - _start);
  try {
    int value = std::stoi(symbol);
    Token t(TOKEN_NUMBER, _input, _start, _end);
    return t;
  } catch (std::invalid_argument e) {}

  if (symbol == "NIL") {
    Token t(TOKEN_NIL, _input, _start, _end);
    return t;
  }
  
  Token t(TOKEN_SYMBOL, _input, _start, _end);
  return t;
}

bool Lexer::isSymbolly() const {
  if (_end >= _input.size()) {
    return false;
  }

  char c = _input[_end];
  
  return c != '.' &&
         c != '(' &&
         c != ')' &&
         c != ' ' &&
         c != '\t' &&
         c != '\r' &&
         c != '\n';
}

bool Lexer::isWhitespace() const {
  if (_end >= _input.size()) {
    return false;
  }
  
  char c = _input[_end];
  
  return c == ' ' ||
         c == '\t' ||
         c == '\n' ||
         c == '\r';
}
