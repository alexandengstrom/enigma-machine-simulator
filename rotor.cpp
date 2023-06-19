#include "rotor.h"

Rotor::Rotor(std::string const& wiring, char notch) {
  this->wiring = wiring;
  input_table = wiring;
  output_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  this->notch = notch;
}

int Rotor::forward(int signal) {
  return output_table.find(input_table[signal]);
}

int Rotor::backward(int signal) {
  return input_table.find(output_table[signal]);
}

void Rotor::rotate() {
  output_table = output_table.substr(1) + output_table[0];
  input_table = input_table.substr(1) + input_table[0];
}

bool Rotor::on_notch() {
  return output_table[0] == notch;
}

void Rotor::setup_position(char letter) {
  int index = static_cast<size_t>(letter - 'A');
    for (int n = 0; n < index; n++) {
      rotate();
    }
}

void Rotor::setup_ring(int setting) {
  for (int n = 0; n < setting - 1; n++) {
    output_table = output_table.substr(25) + output_table.substr(0, 25);
    input_table = input_table.substr(25) + input_table.substr(0, 25);
  }

  int notch_index = static_cast<int>(notch - 'A');
  notch = static_cast<char>((26 + notch_index - setting) % 26 + 'A');
}
