#include "ParseException.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& out, const ParseException& pe) {
  int start = pe.getStart();
  int end = pe.getEnd();
  out << "PARSE EXCEPTION: " << pe.getError() << std::endl;
  std::string pre = pe.getInput().substr(0, start);
  std::string token = pe.getInput().substr(start, end - start);
  std::string post = pe.getInput().substr(end);
  out << pre << " [" << token << "] " << post;
  return out;
}
