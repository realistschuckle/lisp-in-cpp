#include <iostream>
#include <string>
#include "Evaluator.hpp"
#include "Parser.hpp"
#include "ParseException.hpp"
#include "UnboundException.hpp"
#include "SyntaxException.hpp"
#include "ArgumentsException.hpp"

int main(int nargs, char* cargs[]) {
  Environment env;

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
      std::cout << "Unbuond Exception: " << ue.what() << std::endl;
    } catch (SyntaxException& se) {
      std::cout << "Syntax Exception: " << se.what() << std::endl;
    } catch (ArgumentsException& ae) {
      std::cout << "Arguments Exception: " << ae.what() << std::endl;
    }
  }
  
  return 0;
}
