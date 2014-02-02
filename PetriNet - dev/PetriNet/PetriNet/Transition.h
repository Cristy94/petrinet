#ifndef __TRANSITION_H_
#define __TRANSITION_H_

#define mWIDTH 20
#define mHEIGHT 70

#include <vector>

#include "IElement.h"

using namespace std;

class Transition : public IElement {

    public:

        static const int width = mWIDTH;
        static const int height = mHEIGHT;

	    Transition() 
	    {
		    tokens = NULL;
		    position = NULL;
	    }

	    Transition(Point *initialPosition)
	    {
		    position = initialPosition;
            tokens   = new vector<Token*>();
	    }

        Point *centerPosition(){

            Point *p = new Point();

            p->setX(position->getX() + mWIDTH/2);
            p->setY(position->getY() + mHEIGHT/2);

            return p;
        }
};

#endif
	