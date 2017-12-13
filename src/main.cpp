#include <iostream>
#include <memory>
#include <string>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Primitive.hpp"
#include "ParseException.hpp"
#include "EvaluationException.hpp"
#include "Environment.hpp"
#include "Evaluator.hpp"

int main(int nargs, char* cargs[]) {
  std::string input;

  while (true) {
    std::cout << "> ";
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    
    Lexer lexer(input);
    Parser parser(lexer);
    Evaluator eval(Environment::global());

    try {
      eval.reset();
      std::shared_ptr<Primitive> expression = parser.parse();
      std::cout << "Parsed: " << *expression << std::endl;
      expression->accept(&eval);
      std::cout << "Evaluated: " << eval.getResult() << std::endl;
    } catch(ParseException* pe) {
      std::cerr << "Exception: " << *pe << std::endl;
      delete pe;
    } catch(EvaluationException* ee) {
      std::cerr << "Exception: " << *ee << std::endl;
      delete ee;
    }
  }
  
  return 0;
}

