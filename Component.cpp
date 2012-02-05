#include "Component.h"
#include <iostream>
#include <stdlib.h>

std::vector<int> Component::tokenizer(std::string input, std::vector<int> swaps){
	char *in = new char[input.size()];
	strcpy(in,input.c_str());
	char *tokens = strtok(in, " ");
	while(tokens != NULL){
		 int skew = atoi(tokens);
		 swaps.push_back(skew);
		 tokens = strtok(NULL, " ");
	}
	delete []in;
	delete []tokens;
	return swaps;

}

