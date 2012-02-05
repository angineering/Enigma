#include "Rotor.h"
#include <iostream>
#include <vector>

Rotor::Rotor(std::string config){
	offsets = tokenizer(config, offsets);	
	//store offsets and not chars
	for(int i=0;i<ALPHABET_LENGTH;i++){
		int offset = (offsets[i] - i)%ALPHABET_LENGTH;
		offsets[i] = offset;
		//populate reverse offsets array
		int revOff = (i+offset)%ALPHABET_LENGTH;
		if(revOff <0) revOff = (revOff+ALPHABET_LENGTH)%ALPHABET_LENGTH;
		revOffset[revOff] = (-offset)%ALPHABET_LENGTH;
	}
	position = 0;

}
bool Rotor::rotate(){
	if(position>=(ALPHABET_LENGTH-1)){
		position=0;
		return true;
	}
	else {
		++position;
		return false;
	}
}
Rotor::~Rotor(){
}
void Rotor::mapIn(int* chr){
	int chrPos = (ALPHABET_LENGTH+(*chr-position))%ALPHABET_LENGTH;
	*chr += offsets[chrPos];
	//make sure our character is valid
	*chr = (*chr+ALPHABET_LENGTH)%ALPHABET_LENGTH;
}
void Rotor::mapOut(int* chr){
	int chrPos = (ALPHABET_LENGTH+(*chr-position))%ALPHABET_LENGTH;
	*chr += revOffset[chrPos];
	*chr %= ALPHABET_LENGTH;
	if(*chr<0){
		*chr = (ALPHABET_LENGTH+*chr)%ALPHABET_LENGTH;
	}
}
int Rotor::getPosition(){
	return position;
}
int Rotor::getOffset(int i){
	int val = offsets[i];
	return val;
}

