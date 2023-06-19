#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>

class Reflector {
 public:
  Reflector(std::string const& wiring);
  int reflect(int signal);

 private:
  std::string wiring;
};

#endif
