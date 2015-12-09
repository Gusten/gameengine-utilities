#ifndef _Camera_h
#define _Camera_h

#include <math.h>
#include "../math/Float3.h"

using namespace gameutil;

class Camera 
{
public:

	// Camera is represented using the 3 vectors position, forward and up.
	Float3 position;
	Float3 forward;
	Float3 up;


};

#endif // _Camera_h