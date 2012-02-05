#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "Component.h"
#include <string>

class Plugboard : public Component{
		int plugboard[ALPHABET_LENGTH];
	public:
		Plugboard();
		~Plugboard();
		//initially every char without a swap value
		//maps to itself
		void initialize();
		//adds swap values 
		void configure(std::string);
		/* Maps a character to its swap value, 
		 * or itself if there is no swap value.
		 * O(1) */
		void mapChar(int*);

};

#endif
