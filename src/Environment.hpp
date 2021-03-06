#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>
#include <string>
#include "Primitive.hpp"
#include "Symbol.hpp"

class Environment {
public:
  Environment();
  Environment(Environment* parent);
  bool has(Symbol* symbol) const;
  Primitive* get(Symbol* symbol) const;
  void set(Symbol* symbol, Primitive* value);

  friend std::ostream& operator<<(std::ostream& out, const Environment& env);
private:
  Environment* _parent;
  std::map<std::string, Primitive*> _values;
};

#endif
