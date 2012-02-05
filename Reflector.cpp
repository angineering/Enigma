#include "Reflector.h"


void Reflector::reflect(int* x){
	*x = (*x+(ALPHABET_LENGTH/2))%ALPHABET_LENGTH;
}
