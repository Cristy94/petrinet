#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

class Point {
    private:
	    int x;
	    int y;

    public:

        Point(int xx = 0, int yy = 0) : x(xx), y(yy){};

	    void set(int newX, int newY)
	    {
		    x = newX;
		    y = newY;
	    }
    
	    int getX()
	    {
		    return x;
	    }

	    int getY()
	    {
		    return y;
	    }

	    void setX(int value)
	    {
		    x = value;
	    }

	    void setY(int value)
	    {
		    y = value;
	    }
};

#endif
