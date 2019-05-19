#pragma once
#include <vector>
#include "ConsolePoint.h"
class ConsoleShape
{
private:
	int minWidth, maxWidth, minHeight, maxHeight; //variables used to calculate label area
	int pointWidth; // how wide are the points we connect, the diagonal lines and the vertical lines
	std::vector<ConsolePoint> points;
public:
	ConsoleShape(int pointWidth = 0);
	ConsoleShape(const ConsoleShape& cs);
	ConsoleShape&operator=(const ConsoleShape& cs);
	~ConsoleShape();

	int getPointWidth()const;
	void setPointWidth(int pointWidth);

	void addPoint(const ConsolePoint& cp);
	char* drawShape(const int screenWidth, const int screenHeight, const char buildingSymbol,
		const char blankSpace, char *emptyScreen);
};

