#include "Lexer.hpp"
#include "TokenType.hpp"

Lexer::Lexer(std::string input)
  : _input(input),
    _start(0),
    _end(0) {}

std::shared_ptr<Token> Lexer::next() {
  if (_input.size() == 0 || _end >= _input.size()) {
    return std::make_shared<Token>(TOKEN_EOF, "", _start, _end);
  }
  
  std::shared_ptr<Token> ptr;
  while (Lexer::isWhitespace(_input[_end])) {
    _end += 1;
  }
  _start = _end;
  if (_input[_end] == '(') {
    ptr = std::make_shared<Token>(TOKEN_OPEN_PAREN, "(", _start, _end + 1);
    _end += 1;
  } else if (_input[_end] == ')') {
    ptr = std::make_shared<Token>(TOKEN_CLOSE_PAREN, ")", _start, _end + 1);
    _end += 1;
  } else if (_input[_end] == '.') {
    ptr = std::make_shared<Token>(TOKEN_DOT, ".", _start, _end + 1);
    _end += 1;
  } else {
    while (Lexer::isTokenCharacter(_input[_end])) {
      _end += 1;
    }
    std::string token = _input.substr(_start, _end - _start);
    if (token == "NIL") {
      ptr = std::make_shared<Token>(TOKEN_NIL, token, _start, _end);
    } else {
      ptr = std::make_shared<Token>(TOKEN_TOKEN, token, _start, _end);
    }
  }
  return ptr;
}

std::string Lexer::getInput() const {
  return _input;
}

bool Lexer::isTokenCharacter(char c) {
  return !Lexer::isWhitespace(c)
    && c != '('
    && c != ')'
    && c != '.';
}

bool Lexer::isWhitespace(char c) {
  return c == ' ' ||
    c == '\t' ||
    c == '\n' ||
    c == '\r';
}
