#ifndef __POSITION_H_
#define __POSITION_H_
#include <iostream>
using namespace std;

class Position
{
	int x;
	int y;

public:
	Position();

	Position(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void changePosition(int newX, int newY)
	{
		this->x = newX;
		this->y = newY;
	}

	int getX();

	int getY();

	int setX();

	int setY();
};

#endif
