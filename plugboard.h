#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <vector>
#include <string>

class Plugboard {
 public:
  Plugboard(std::vector<std::string> pairs);
  int forward(int signal);
  int backward(int signal);

 private:
  std::string input_table;
  std::string output_table;
};

#endif
