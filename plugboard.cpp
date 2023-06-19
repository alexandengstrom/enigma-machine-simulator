#include "plugboard.h"

Plugboard::Plugboard(std::vector<std::string> pairs) {
  input_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  output_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (const std::string& pair: pairs) {
    char a = pair[0];
    char b = pair[1];
    int pos_a = output_table.find(a);
    int pos_b = output_table.find(b);
    output_table[pos_a] = b;
    output_table[pos_b] = a;
  }
}

int Plugboard::forward(int signal) {
  return output_table.find(input_table[signal]);
}

int Plugboard::backward(int signal) {
  return input_table.find(output_table[signal]);
}
