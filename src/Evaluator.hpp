#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include "Environment.hpp"
#include "Primitive.hpp"

class Evaluator {
public:
  Evaluator(Environment* env) : _env(env) {}
  Primitive* eval(Primitive* expression);

private:
  Environment* _env;
};

#endif
