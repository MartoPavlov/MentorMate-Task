#pragma once
class ConsolePoint
{
private:
	int x, y;// the coordinates of a point in the console (as index).
public:
	ConsolePoint(int x = 0, int y = 0);
	ConsolePoint(const ConsolePoint& cp);
	ConsolePoint&operator=(const ConsolePoint& cp);
	~ConsolePoint();

	int getX()const;
	int getY()const;
};

