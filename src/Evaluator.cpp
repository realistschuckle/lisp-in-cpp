#include <iostream>
#include "Evaluator.hpp"
#include "SyntaxException.hpp"
#include "ArgumentsException.hpp"
#include "UnboundException.hpp"
#include "Symbolp.hpp"
#include "Consp.hpp"
#include "Listp.hpp"
#include "Nilp.hpp"
#include "Functionp.hpp"
#include "Closure.hpp"
#include "Closurep.hpp"

Primitive* Evaluator::eval(Primitive* expression) {
  Closurep closurep;
  Symbolp symbolp;
  Consp consp;
  Listp listp;
  Nilp nilp;
  expression->accept(&symbolp);
  expression->accept(&consp);
  expression->accept(&listp);
  expression->accept(&nilp);
  
  if (symbolp.isSymbol()) {
    return _env->get(symbolp.getSymbol());
  } else if(!consp.isCell() || nilp.isNil()) {
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
	throw ArgumentsException(expression->toString());
      }
      Symbol* var = symbolp.getSymbol();
      Primitive* value = consp.getCell()->cdr();
      consp.reset();
      value->accept(&consp);
      if (!consp.isCell()) {
	throw ArgumentsException(expression->toString());
      }

      Evaluator evaluator(_env);
      value = evaluator.eval(consp.getCell()->car());
      _env->set(var, value);
      return var;
    }
    if (opName == "LAMBDA") {
      if (nilp.isNil() || !consp.isCell()) {
	throw ArgumentsException(expression->toString());
      }
      Primitive* pargs = consp.getCell()->car();
      Primitive* pbody = consp.getCell()->cdr();

      Listp listp;
      consp.reset();
      pargs->accept(&listp);
      pargs->accept(&consp);
      if (!listp.isList()) {
	throw ArgumentsException(expression->toString());
      }
      Cell* largs = consp.getCell();
      
      consp.reset();
      pbody->accept(&consp);
      if (!consp.isCell()) {
	throw ArgumentsException(expression->toString());
      }
      Primitive* lbody = consp.getCell()->car();

      return new Closure(_env, largs, lbody);
    }
    if (opName == "IF") {
      if (nilp.isNil() || !consp.isCell()) {
	throw ArgumentsException(expression->toString());
      }
      Primitive* test = consp.getCell()->car();

      Primitive* rest = consp.getCell()->cdr();
      consp.reset();
      nilp.reset();
      rest->accept(&nilp);
      rest->accept(&consp);
      if (nilp.isNil() || !consp.isCell()) {
	throw ArgumentsException(expression->toString());
      }
      Primitive* texpr = consp.getCell()->car();

      rest = consp.getCell()->cdr();
      consp.reset();
      nilp.reset();
      rest->accept(&nilp);
      rest->accept(&consp);
      if (nilp.isNil() || !consp.isCell()) {
	throw ArgumentsException(expression->toString());
      }
      Primitive* fexpr = consp.getCell()->car();

      nilp.reset();
      Evaluator evaluator(_env);
      evaluator.eval(test)->accept(&nilp);
      if (nilp.isNil()) {
	return evaluator.eval(fexpr);
      }
      return evaluator.eval(texpr);
    }
    if (_env->has(symbolp.getSymbol())) {
      Functionp functionp;
      Primitive* fn = _env->get(symbolp.getSymbol());
      fn->accept(&functionp);
      fn->accept(&closurep);
      if (functionp.isFunction()) {
	Evaluator evaluator(_env);
	return functionp.getFunction()->exec(evalList(consp.getCell()));
      }
      if (closurep.isClosure()) {
	return closurep.getClosure()->evaluate(evalList(consp.getCell()));
      }
    }
    if (opName == "QUIT") {
      return 0;
    }
    throw UnboundException(opName);
  }
  consp.reset();
  op->accept(&consp);
  if (consp.isCell()) {
    Primitive* activeop = eval(op);
    activeop->accept(&closurep);
    if (closurep.isClosure()) {
      consp.reset();
      args->accept(&consp);
      return closurep.getClosure()->evaluate(evalList(consp.getCell()));
    }
  }

  throw SyntaxException(expression->toString());
}

Cell* Evaluator::evalList(Cell* cell) {
  Nilp nilp;
  cell->accept(&nilp);
  if (nilp.isNil()) {
    return cell;
  }
  Primitive* value = eval(cell->car());
  Consp consp;
  cell->cdr()->accept(&consp);

  if (consp.isCell()) {
    return new Cell(value, evalList(consp.getCell()));
  } else {
    return new Cell(value, eval(cell->cdr()));
  }
}
