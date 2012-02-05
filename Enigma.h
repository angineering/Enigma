#ifndef ENIGMA_H
#define ENIGMA_H

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

#include <string>
#include <vector>

class Enigma{
		Plugboard* plugboard;
		Reflector* reflector;
		std::vector<Rotor*> m_rotors;
	public:
		Enigma();
		~Enigma();
		void addRotor(std::string);
		void configurePlugboard(std::string);
		void encrypt(int*);
		//maps a char through all the rotors (in)
		void mapIn(int*);
		//maps a char backwards through the rotors (out)
		void mapOut(int*);
};



#endif
