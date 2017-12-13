#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>
#include <memory>
#include "Primitive.hpp"

class Environment {
public:
  static std::shared_ptr<Environment> global();
  static std::shared_ptr<Environment> make(std::shared_ptr<Environment> parent);
  std::shared_ptr<Primitive> get(std::shared_ptr<Primitive> symbol);
  void set(std::shared_ptr<Primitive> symbol, std::shared_ptr<Primitive> value);

private:
  static std::shared_ptr<Environment> _global;
  Environment();
  Environment(std::shared_ptr<Environment> parent);
  std::shared_ptr<Environment> _parent;
  std::map<std::shared_ptr<Primitive>, std::shared_ptr<Primitive>> _dict;
};

#endif
