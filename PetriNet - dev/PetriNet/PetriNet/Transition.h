#ifndef __TRANSITION_H_
#define __TRANSITION_H_

#include <vector>

#include "IElement.h"

using namespace std;

class Transition : public IElement {

    public:
	    Transition() 
	    {
		    tokens = NULL;
		    position = NULL;
	    }

	    Transition(Point *initialPosition)
	    {
		    position = initialPosition;
            tokens   = new vector<Token*>();
	    }
};

#endif
	