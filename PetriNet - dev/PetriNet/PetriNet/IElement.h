#ifndef __IELEMENT_H_
#define __IELEMENT_H_
#include <vector>
#include "Token.h"
#include "Position.h"
using namespace std;

class IElement
{
	Position *position;

public:
	IElement();

	virtual void createPlace();
	virtual void createToken();
	virtual void createTransition();
	virtual void createArc();
	

};


#endif 