#ifndef __IELEMENT_H_
#define __IELEMENT_H_
#include <vector>
#include "Token.h"
#include "Position.h"
#include "IEdit.h"
using namespace std;

class IElement
{

public:
	IElement();

	virtual void createPlace();
	virtual void createToken();
	virtual void createTransition();
	virtual void createArc();
};


#endif 