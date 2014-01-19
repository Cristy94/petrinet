#ifndef __IEDIT_H_
#define __IEDIT_H_
#include "Transition.h"
#include "Place.h"
#include "Arc.h"

class IEdit
{
public:
	virtual void editPlace(Place *place);
	virtual void editTransition(Transition *transition);
	virtual void editArc(Arc *arc);
	virtual void addPlace(Place *place);
	virtual void addTransition(Transition *transition);
	virtual void addArc(Arc *arc);
	virtual void editNumberOfTokens();
	virtual void editPosition();
	virtual void editElement();
};

#endif
