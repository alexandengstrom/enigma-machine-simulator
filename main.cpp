#include "enigma.h"
#include "plugboard.h"
#include "rotor.h"
#include "reflector.h"

#include <string>
#include <vector>
#include <iostream>

int main() {
  Plugboard plugboard{std::vector<std::string>{"AB", "CD", "DF"}};

  // More historical rotors and reflectors can be found here:
  // https://en.wikipedia.org/wiki/Enigma_rotor_details
  
  Rotor rotor_i  {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q'};
  Rotor rotor_ii {"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E'};
  Rotor rotor_iii{"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V'};
  Rotor rotor_iv {"ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J'};
  Rotor rotor_v  {"VZBRGITYUPSDNHLXAWMJQOFECK", 'Z'};
  
  Reflector reflector_a{"EJMZALYXVBWFCRQUONTSPIKHGD"};
  Reflector reflector_b{"YRUHQSLDPXNGOKMIEBFZCWVJAT"};
  Reflector reflector_c{"FVPJIAOYEDRZXWGCTKUQSBNMHL"};

  std::vector<Rotor> rotors{rotor_i, rotor_ii, rotor_iii};
  
  Enigma enigma{reflector_b, rotors, plugboard};
  std::vector<int> ring_setting{3,2,3};
  std::cout << enigma.encrypt("SUPERSECRETMESSAGE", "XYZ", ring_setting) << std::endl;
  return 0;
}
