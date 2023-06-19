#ifndef ENIGMA_H
#define ENIGMA_H

#include "plugboard.h"
#include "rotor.h"
#include "reflector.h"
#include <string>
#include <vector>

class Enigma {
 public:
  Enigma(Reflector & reflector, std::vector<Rotor> & rotors, Plugboard & plugboard);

  void setup_starting_position(std::string const& key);
  void setup_rings(std::vector<int> const& ring_settings);
  std::string encrypt(std::string const& str, std::string const& key, std::vector<int> const& ring_setting);
 private:
  char encrypt_letter(char letter);
  void rotate_rotors();
  int to_signal(char letter);
  char to_letter(int signal);

  Reflector& reflector;
  std::vector<Rotor>& rotors;
  Plugboard& plugboard;
  
};

#endif
