#ifndef PARSEEXCEPTION_HPP
#define PARSEEXCEPTION_HPP

#include <string>

class ParseException {
public:
  ParseException(std::string error, std::string input, int start, int end)
    : _error(error), _input(input), _start(start), _end(end) {}
  
  inline std::string getError() const { return _error; }
  inline std::string getInput() const { return _input; }
  inline int getStart() const { return _start; }
  inline int getEnd() const { return _end; }

private:
  std::string _error;
  std::string _input;
  int _start;
  int _end;
};

std::ostream& operator<<(std::ostream& out, const ParseException& pe);

#endif
