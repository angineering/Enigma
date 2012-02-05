#ifndef ROTOR_H
#define ROTOR_H

#include "Component.h"
#include <string>
#include <vector>

/* Note: we want to store the offset for each char.
 * Note: There is a rotor offset(position) and a 
 *		 char offset (encoding)
 */

class Rotor : public Component{
		int position;
		std::vector<int> offsets;
		//stores the reverse offsets so we know how to map backwards
		int revOffset[ALPHABET_LENGTH];
	public:
		Rotor(std::string);
		~Rotor();
		bool rotate();
		void mapIn(int*);
		int getPosition();
		int getOffset(int);
		void mapOut(int*);
};

#endif
