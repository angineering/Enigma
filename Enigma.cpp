#include "Enigma.h"

#include <iostream>

Enigma::Enigma(){
	plugboard = new Plugboard();
	reflector = new Reflector();
}
Enigma::~Enigma(){
	delete plugboard;
	delete reflector;
	m_rotors.~vector();
}
void Enigma::addRotor(std::string setup){
	Rotor* newRotor = new Rotor(setup);
	if(newRotor != NULL){
		m_rotors.push_back(newRotor);
	} else std::cout<<"Could not add Rotor"<<std::endl;
}
void Enigma::configurePlugboard(std::string setup){
	plugboard->configure(setup);
}

void Enigma::encrypt(int* pChr){
	
	//plugboard in
	plugboard->mapChar(pChr);
	
	//rotors in
	Enigma::mapIn(pChr);
	
	//reflect character
	reflector->reflect(pChr);
	
	//rotors out
	Enigma::mapOut(pChr);
	
	//plugboard out
	plugboard->mapChar(pChr);	
	
	//print character to output board
	char result = 'A' + *pChr;
	std::cout<<result;
	
	/*rotate the appropriate rotors.
	* rotate() returns true when a full rotation is made,
	*/
	int i=0;
	while(i<m_rotors.size() && m_rotors[i]->rotate()){ 
		i++;
	}

}
void Enigma::mapIn(int* chr){
	for(int i=0; i<m_rotors.size(); i++){
		m_rotors[i]->mapIn(chr);
	}
}
void Enigma::mapOut(int* chr){
	std::vector<Rotor*>::reverse_iterator ritr;
	for(ritr = m_rotors.rbegin(); ritr < m_rotors.rend(); ++ritr){
		(*ritr)->mapOut(chr);
	}
}

