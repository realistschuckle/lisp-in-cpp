#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include "Environment.hpp"
#include "Primitive.hpp"

class Evaluator {
public:
  Evaluator(Environment* env) : _env(env) {}
  Primitive* eval(Primitive* expression);

private:
  Cell* evalList(Cell* cell);
  Environment* _env;
};

#endif
