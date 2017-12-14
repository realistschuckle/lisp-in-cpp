#include "Evaluator.hpp"
#include "SyntaxException.hpp"
#include "ArgumentsException.hpp"
#include "UnboundException.hpp"
#include "Symbolp.hpp"
#include "Consp.hpp"
#include "Listp.hpp"
#include "Nilp.hpp"

Primitive* Evaluator::eval(Primitive* expression) {
  Symbolp symbolp;
  Consp consp;
  Listp listp;
  Nilp nilp;
  expression->accept(&symbolp);
  expression->accept(&consp);
  expression->accept(&listp);
  
  if (symbolp.isSymbol()) {
    return _env->get(symbolp.getSymbol());
  } else if(!consp.isCell()) {
    return expression;
  }

  if (!listp.isList()) {
    throw SyntaxException(expression->toString());
  }

  Primitive* op = consp.getCell()->car();
  Primitive* args = consp.getCell()->cdr();

  symbolp.reset();
  nilp.reset();
  consp.reset();
  
  op->accept(&symbolp);
  args->accept(&nilp);
  args->accept(&consp);
  if (symbolp.isSymbol()) {
    std::string opName = symbolp.getSymbol()->getValue();
    if (opName == "QUOTE") {
      if (nilp.isNil() || !consp.isCell()) {
	throw ArgumentsException(expression->toString());
      }
      return consp.getCell()->car();
    }
    if (opName == "DEFINE") {
      if (nilp.isNil() || !consp.isCell()) {
	throw ArgumentsException(expression->toString());
      }
      symbolp.reset();
      consp.getCell()->car()->accept(&symbolp);
      if (!symbolp.isSymbol()) {
	throw new ArgumentsException(expression->toString());
      }
      Symbol* var = symbolp.getSymbol();
      Primitive* value = consp.getCell()->cdr();
      consp.reset();
      value->accept(&consp);
      if (!consp.isCell()) {
	throw new ArgumentsException(expression->toString());
      }

      Evaluator evaluator(_env);
      value = evaluator.eval(consp.getCell()->car());
      _env->set(var, value);
      return var;
    }
    if (opName == "QUIT") {
      return 0;
    }
    throw UnboundException(opName);
  }

  throw SyntaxException(expression->toString());
}
