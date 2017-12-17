#include <iostream>
#include <fstream>
#include <string>
#include "Evaluator.hpp"
#include "Parser.hpp"
#include "ParseException.hpp"
#include "UnboundException.hpp"
#include "SyntaxException.hpp"
#include "ArgumentsException.hpp"

int main(int nargs, char* cargs[]) {
  Environment env;

  std::string library = "library.lisp";
  if (nargs > 1) {
    library = cargs[1];
  }
  std::cout << "loading " << library << std::endl;
  std::ifstream ifin(library);

  if (ifin.is_open()) {
    int i = 0;
    for (std::string line; std::getline(ifin, line); ) {
      if (line.size() == 0) continue;
      i += 1;
      Parser parser(line);
      try {
	Primitive* expression = parser.parse();
	Evaluator evaluator(&env);
	std::cout << *evaluator.eval(expression) << " ";
      } catch (ParseException& pe) {
	std::cout << "Parse Exception: " << pe.what() << std::endl;
      } catch (UnboundException& ue) {
	std::cout << "Unbound Exception: " << ue.what() << std::endl;
      } catch (SyntaxException& se) {
	std::cout << "Syntax Exception: " << se.what() << std::endl;
      } catch (ArgumentsException& ae) {
	std::cout << "Arguments Exception: " << ae.what() << std::endl;
      }
    }
    std::cout << std::endl;
  }

  while (true) {
    std::string input;
    std::cout << "> ";
    std::getline(std::cin, input);
    
    Parser parser(input);
    try {
      Primitive* expression = parser.parse();
      Evaluator evaluator(&env);
      Primitive* result = evaluator.eval(expression);

      if (result) {
	std::cout << *result << std::endl;
      } else {
	break;
      }
    } catch (ParseException& pe) {
      std::cout << "Parse Exception: " << pe.what() << std::endl;
    } catch (UnboundException& ue) {
      std::cout << "Unbound Exception: " << ue.what() << std::endl;
    } catch (SyntaxException& se) {
      std::cout << "Syntax Exception: " << se.what() << std::endl;
    } catch (ArgumentsException& ae) {
      std::cout << "Arguments Exception: " << ae.what() << std::endl;
    }
  }
  
  return 0;
}
