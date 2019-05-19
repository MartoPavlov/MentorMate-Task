#include "ConsolePoint.h"


ConsolePoint::ConsolePoint(int x, int y)
{
	this->x = x;
	this->y = y;
}
ConsolePoint::ConsolePoint(const ConsolePoint& cp)
{
	this->x = cp.x;
	this->y = cp.y;
}
ConsolePoint&ConsolePoint::operator=(const ConsolePoint& cp)
{
	if (this != &cp)
	{
		this->x = cp.x;
		this->y = cp.y;
	}
	return *this;
}

ConsolePoint::~ConsolePoint() = default;

//getters
int ConsolePoint::getX()const { return x; }
int ConsolePoint::getY()const { return y; }
