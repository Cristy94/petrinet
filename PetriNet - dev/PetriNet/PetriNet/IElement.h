#ifndef __IELEMENT_H_
#define __IELEMENT_H_
#include <vector>

#include "Token.h"
#include "point.h"

using namespace std;

//Base class for PetriNet elements: Places and Transitions
class IElement {

    protected: 
	    Point *position;
        vector<Token*> *tokens;	

    public:
	    IElement()
	    {
		    position = new Point();
	    }

	   	void setNumberOfTokens(int number)
	    {
		    tokens->resize(number);
	    }
	
        //Sets top-left position of the element
	    void setPosition(int x, int y)
	    {
		    position->setX(x);
		    position->setY(y);
	    }

};


#endif 