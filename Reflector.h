#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "Component.h"

/* Reflects the input by the function
 * r(x) = (x+13)%26.
 * The wiring is not configurable.
 */

class Reflector : public Component{
	public:
		void reflect(int*);

};

#endif
