#ifndef __IELEMENT_H_
#define __IELEMENT_H_
#include <vector>
#include "Token.h"
#include "Position.h"
using namespace std;

class IElement
{

protected: 
	Position *position;

public:
	IElement()
	{
		position = new Position();
	}

	virtual void setNumberOfTokens(int number);
	
	void setPosition(int x, int y)
	{
		position->setX(x);
		position->setY(y);
	}
};


#endif 