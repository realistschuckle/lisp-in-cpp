#include <iostream>
#include <string>
#include <vector>
#include "Parser.hpp"
#include "ParseException.hpp"

int main(int nargs, char* cargs[]) {
  std::vector<std::string> inputs = { "", "NIL", "1", "HELLO", "()", "(12345)", "(1 . 12345 )", "(1 2 NIL HELLO)", "(s (t . u) v . (w . nil))", "(. 3)", "(", "(1 .)", "(1", ")" };
  
  for (std::string input : inputs) {
    Parser parser(input);
    try {
      std::cout << "Input: '" << input << "'" << std::endl;
      Primitive* p = parser.parse();
      std::cout << "Parsed: " << *p << std::endl;
    } catch (ParseException& pe) {
      std::cout << "ERROR: " << pe.what() << std::endl;
    }
    std::cout << std::endl;
  }
  
  return 0;
}
