#ifndef __PLACE_H_
#define __PLACE_H_


#include <vector> 

#include "IElement.h"


class Place : public IElement {

    public:
	    Place()
	    {
		    position = NULL;
		    tokens   = new vector<Token*>();
	    }

	    Place(Point *initialPosition)
	    {
		    position = initialPosition;
            tokens   = new vector<Token*>();
	    }

};

#endif
	