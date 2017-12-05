#include <iostream>
#include <memory>
#include <string>

#include "Lexer.hpp"
#include "TokenType.hpp"

int main(int nargs, char* cargs[]) {
  {
    Lexer lexer("(hello-world 14 . nil)");
    while (auto t = lexer.next()) {
      if (t->getType() == TOKEN_EOF) {
	break;
      }
      std::cout << *t << std::endl;
    }
  }
  return 0;
}

