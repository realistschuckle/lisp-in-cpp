#include <iostream>
#include <memory>
#include "Nil.hpp"
#include "Integer.hpp"
#include "Symbol.hpp"
#include "Cell.hpp"

int main(int nargs, char* cargs[]) {
  auto nil = Nil::make();
  std::cout << *nil << std::endl;
  
  auto i = Integer::make(3);
  std::cout << *i << std::endl;
  
  auto sym = Symbol::make("hello-world");
  std::cout << *sym << std::endl;
  
  sym = Symbol::make("goodbye-cruel-world");
  std::cout << *sym << std::endl;

  sym = Symbol::make("hello-world");
  std::cout << *sym << std::endl;

  std::cout << "Number of symbols: " << Symbol::numberOfSymbols() << std::endl;

  auto c = Cell::cons(i, sym);
  std::cout << *c << std::endl;

  c = Cell::cons(i, Cell::cons(sym, nil));
  std::cout << *c << std::endl;
  
  return 0;
}
