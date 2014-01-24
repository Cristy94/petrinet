#ifndef _ARCS_H_
#define _ARCS_H_
#include "IElement.h"

class Arcs {

public:

	IElement *source;
	IElement *destination;

	Arcs()
	{
		this->source = NULL;
		this->destination = NULL;
	}
	
	Arcs(IElement *source, IElement *destination)
	{
		this->source = source;
		this->destination = destination;
	}

};


#endif