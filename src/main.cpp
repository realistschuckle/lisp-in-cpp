#include <iostream>
#include <memory>
#include <string>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "ParseException.hpp"

int main(int nargs, char* cargs[]) {
  std::string input;

  while (true) {
    std::cout << "> ";
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    
    Lexer lexer(input);
    Parser parser(lexer);

    try {
      std::cout << parser.parse() << std::endl;
    } catch(ParseException* pe) {
      std::cerr << "Exception: " << *pe << std::endl;
      delete pe;
    }
  }
  
  return 0;
}

