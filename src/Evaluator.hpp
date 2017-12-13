#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include <memory>
#include "Environment.hpp"
#include "PrimitiveVisitor.hpp"
#include "Primitive.hpp"
#include "Cell.hpp"
#include "Symbol.hpp"
#include "Integer.hpp"
#include "Nil.hpp"

class Evaluator : public PrimitiveVisitor {
public:
  Evaluator(std::shared_ptr<Environment> environment);
  inline Primitive* getResult() const {
    return _result;
  }
  
  virtual void visit(Nil* primitive);
  virtual void visit(Integer* primitive);
  virtual void visit(Symbol* primitive);
  virtual void visit(Cell* primitive);

  virtual void reset();

private:
  static void noDelete(Primitive* p);
  std::shared_ptr<Environment> _env;
  Primitive*_result;
};

#endif
