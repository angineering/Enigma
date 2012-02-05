#include "Plugboard.h"
#include <iostream>
#include <vector>

Plugboard::Plugboard(){
	Plugboard::initialize();
}

Plugboard::~Plugboard(){
}

void Plugboard::initialize(){
	//let every character initially map to itself
	for(int i=0; i<ALPHABET_LENGTH;i++){
		plugboard[i]=i;
	}
}

void Plugboard::configure(std::string configure){
	std::vector<int> swap;
	swap = tokenizer(configure,swap);

	std::vector<int>::iterator itr;
	for(itr = swap.begin(); itr<swap.end(); itr+=2){
		plugboard[*itr] = *(itr+1);
		plugboard[*(itr+1)] = *itr;
	}
}

void Plugboard::mapChar(int* pChar){
	*pChar = plugboard[*pChar];
}
