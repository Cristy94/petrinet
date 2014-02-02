#ifndef __PLACE_H_
#define __PLACE_H_

#define mRADIUS 70

#include <vector> 

#include "IElement.h"


class Place : public IElement {

    public:

        static const int radius = mRADIUS;

	    Place()
	    {
		    position = NULL;
		    tokens   = new vector<Token*>();
	    }

	    Place(Point *initialPosition)
	    {
		    position = initialPosition;
            tokens   = new vector<Token*>();
	    }


        Point *centerPosition(){

            Point *p = new Point();

            p->setX(position->getX() + mRADIUS/2);
            p->setY(position->getY() + mRADIUS/2);

            return p;
        }

};

#endif
	