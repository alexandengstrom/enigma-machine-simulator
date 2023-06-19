#include "enigma.h"

Enigma::Enigma(Reflector & reflector, std::vector<Rotor> & rotors, Plugboard & plugboard) :
  reflector(reflector), rotors(rotors), plugboard(plugboard) {}

void Enigma::setup_starting_position(std::string const& key) {
  for (size_t i = 0; i < key.length(); i++) {
    rotors[i].setup_position(key[i]);
  }
}

void Enigma::setup_rings(std::vector<int> const& ring_settings) {
  for (size_t i = 0; i < ring_settings.size(); i++) {
    rotors[i].setup_ring(ring_settings[i]);
  }
}

std::string Enigma::encrypt(std::string const& str,
			    std::string const& key,
			    std::vector<int> const& ring_settings) {
  setup_rings(ring_settings);
  setup_starting_position(key);

  std::string result;
  for (char const& letter : str) {
    result += encrypt_letter(letter);
  }
  return result;
}

char Enigma::encrypt_letter(char letter) {
  rotate_rotors();

  int signal = plugboard.forward(to_signal(letter));
  for (auto it = rotors.rbegin(); it != rotors.rend(); it++) {
    signal = it->forward(signal);
  }

  signal = reflector.reflect(signal);

  for (auto it = rotors.begin(); it != rotors.end(); it++) {
    signal = it->backward(signal);
  }

  return to_letter(plugboard.backward(signal));
}

void Enigma::rotate_rotors() {
  if (rotors[2].on_notch() && rotors[1].on_notch()) {
    rotors[2].rotate();
    rotors[1].rotate();
    rotors[0].rotate();
  }
  else if (rotors[1].on_notch()) {
    rotors[2].rotate();
    rotors[1].rotate();
    rotors[0].rotate();
  }
  else if (rotors[2].on_notch()) {
    rotors[2].rotate();
    rotors[1].rotate();
  }
  else {
    rotors[2].rotate();
  }
}

int Enigma::to_signal(char letter) {
  return letter - 'A';
}

char Enigma::to_letter(int signal) {
  return static_cast<char>(signal + 'A');
}
