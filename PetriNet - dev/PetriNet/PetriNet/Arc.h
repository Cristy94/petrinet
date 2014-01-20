#ifndef _ARCS_H_
#define _ARCS_H_
#include "IElement.h"

class Arcs 
{
	IElement *source;
	IElement *destination;

public:
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