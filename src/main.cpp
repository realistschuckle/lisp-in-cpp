#include <iostream>
#include "Nil.hpp"
#include "Symbol.hpp"
#include "Integer.hpp"
#include "Cell.hpp"

int main(int nargs, char* cargs[]) {
  Nil nil;
  std::cout << "NIL: " << nil << std::endl;

  Integer i(5);
  std::cout << "INT: " << i << std::endl;

  Symbol *s1 = Symbol::make("HELLO");
  std::cout << "SYM: " << *s1 << std::endl;
  std::cout << "count: " << Symbol::count() << std::endl;

  Symbol *s2 = Symbol::make("HELLO");
  std::cout << "SYM: " << *s2 << std::endl;
  std::cout << "count: " << Symbol::count() << std::endl;

  Symbol *s3 = Symbol::make("GOODBYE");
  std::cout << "SYM: " << *s3 << std::endl;
  std::cout << "count: " << Symbol::count() << std::endl;

  Cell c(s1, &i);
  std::cout << "IMP-LIST: " << c << std::endl;

  Cell c1(s2, &nil);
  std::cout << "LIST: " << c1 << std::endl;
  
  Cell c2(s3, &c1);
  Cell c3(&i, &c2);
  std::cout << "LIST: " << c3 << std::endl;

  delete s1;
  delete s3;
  
  return 0;
}
