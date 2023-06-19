#include "reflector.h"

Reflector::Reflector(std::string const& wiring) {
  this->wiring = wiring;
}

int Reflector::reflect(int signal) {
  return wiring[signal] - 'A';
}
