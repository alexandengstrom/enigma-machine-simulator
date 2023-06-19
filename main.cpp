#include "enigma.h"
#include "plugboard.h"
#include "rotor.h"
#include "reflector.h"
#include <string>
#include <iostream>
#include <vector>

int main() {
  Plugboard plugboard{std::vector<std::string>{"AB", "CD", "DF"}};
  Rotor rotor_i{"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q'};
  Rotor rotor_ii{"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E'};
  Rotor rotor_iii{"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V'};
  Reflector reflector_a{"EJMZALYXVBWFCRQUONTSPIKHGD"};
  Reflector reflector_b{"YRUHQSLDPXNGOKMIEBFZCWVJAT"};

  std::vector<Rotor> rotors{rotor_i, rotor_ii, rotor_iii};
  
  Enigma enigma{reflector_b, rotors, plugboard};
  std::vector<int> ring_setting{3,2,3};
  std::cout << enigma.encrypt("SMPQPTFGM", "CAT", ring_setting) << std::endl;
  return 0;
}
