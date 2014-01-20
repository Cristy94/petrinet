#ifndef __IEDIT_H_
#define __IEDIT_H_
#include "Transition.h"
#include "Place.h"
#include "Arc.h"
#include "IElement.h"

class IEdit
{
public:
	virtual void editPlace(Place *place);
	virtual void editTransition(Transition *transition);
	virtual void editArc(Arcs *arc);
	virtual void addPlace(Place *place);
	virtual void addTransition(Transition *transition);
	virtual void addArc(Arcs *arc);
	virtual void editNumberOfTokens();
	virtual void editPosition(IElement *element);
	virtual void editElement();
};

#endif
