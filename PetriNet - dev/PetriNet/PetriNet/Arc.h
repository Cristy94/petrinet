#ifndef _ARCS_H_
#define _ARCS_H_
#include "IElement.h"

class Arcs {

public:

	IElement *source;
	IElement *destination;
    Point *startPosition, *endPosition;
	Arcs()
	{
		this->source = NULL;
		this->destination = NULL;
        startPosition = new Point();
        endPosition = new Point();
	}
	
	Arcs(IElement *source, IElement *destination)
	{
		this->source = source;
		this->destination = destination;
        startPosition = source->centerPosition();
        endPosition = destination->centerPosition();
	}

	

};


#endif