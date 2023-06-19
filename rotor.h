#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor {
 public:
  Rotor(std::string const& wiring, char notch);
  int forward(int signal);
  int backward(int signal);
  void rotate();
  bool on_notch();
  void setup_position(char letter);
  void setup_ring(int setting);
 private:
  std::string wiring;
  std::string input_table;
  std::string output_table;
  char notch;
};

#endif
