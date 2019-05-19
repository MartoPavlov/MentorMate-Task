#include<iostream>
#include<algorithm>
#include "ConsoleShape.h"

ConsoleShape::ConsoleShape(int pointWidth)
{
	this->pointWidth = pointWidth;
	this->minWidth = 0;
	this->minHeight = 0;
	this->maxWidth = 0;
	this->maxHeight = 0;
}
ConsoleShape::ConsoleShape(const ConsoleShape& cs)
{
	this->pointWidth = cs.pointWidth;
	this->minWidth = cs.minWidth;
	this->maxWidth = cs.maxWidth;
	this->minHeight = cs.minHeight;
	this->maxHeight = cs.maxHeight;
	this->points = cs.points;
}
ConsoleShape&ConsoleShape::operator=(const ConsoleShape& cs)
{
	if (this != &cs)
	{
		this->pointWidth = cs.pointWidth;
		this->minWidth = cs.minWidth;
		this->maxWidth = cs.maxWidth;
		this->minHeight = cs.minHeight;
		this->maxHeight = cs.maxHeight;
		this->points = cs.points;
	}
	return *this;
}
ConsoleShape::~ConsoleShape() = default;

//getters and setters
int ConsoleShape::getPointWidth()const { return this->pointWidth; }
void ConsoleShape::setPointWidth(int pointWidth) { this->pointWidth = pointWidth; }
//-------------------

//adds one ConsolePoint to the "points" vector. Also updates the label area variables.
void ConsoleShape::addPoint(const ConsolePoint& cs)
{
	if (points.empty())
	{
		this->minWidth = cs.getX();
		this->maxWidth = cs.getX() + pointWidth;
		this->minHeight = cs.getY();
		this->maxHeight = cs.getY();
	}
	else
	{
		if (this->minWidth > cs.getX())this->minWidth = cs.getX();
		if (this->maxWidth < cs.getX() + pointWidth)this->maxWidth = cs.getX() + pointWidth;
		if (this->minHeight > cs.getY())this->minHeight = cs.getY();
		if (this->maxHeight < cs.getY())this->maxHeight = cs.getY();
	}
	points.push_back(cs);
}
/*
	Connects all the ConsolePoints in the "points" vector.
	The returned label is cutted to fit the virtual screen defined by the
	"screenWidth" and "screenHeight" variables.
*/
char* ConsoleShape::drawShape(const int screenWidth, const int screenHeight, const char buildingSymbol,
	const char blankSpace, char *emptyScreen)
{
	std::fill_n(emptyScreen, screenWidth*screenHeight, ' '); //fill the array with spaces
	for (int i = 1; i < this->points.size(); i++)
	{
		//the distance (in symbols) from A to B for X and Y coordinates
		int diffX = this->points[i].getX() - this->points[i - 1].getX();
		int diffY = this->points[i].getY() - this->points[i - 1].getY();
		//the number of symbols between from A to B - 1(because it doesn't count itself)
		int betweenPoints = std::max(abs(diffX), abs(diffY));
		//how much symbols(spaces) do we add per point to connect A and B for both X and Y
		float stepX = diffX / (float)betweenPoints;
		float stepY = diffY / (float)betweenPoints;
		for (int j = 0; j < betweenPoints + 1; j++)
		{
			//where are we drawing (x,y)
			int cursorX = this->points[i - 1].getX() + (int)(j*stepX);
			int cursorY = this->points[i - 1].getY() + (int)(j*stepY);
			//formal check so we stay in the bounds of the screen
			if (cursorX >= 0 && cursorX < screenWidth&&cursorY >= 0 && cursorY < screenHeight)
			{
				for (int k = 0; k < pointWidth; k++)
				{
					if (cursorX + k < screenWidth)
					{
						emptyScreen[cursorY*screenWidth + cursorX + k] = buildingSymbol;
					}
				}
			}
		}
		//fill the void in the label with "blankSpace"
		if (blankSpace != ' ')//formal check so we don't fill when it's not required
		{
			for (int i = minHeight; i <= std::min(maxHeight, screenHeight - 1); i++)
			{
				for (int j = minWidth; j <= std::min(maxWidth, screenWidth - 1); j++)
				{
					int index = i * screenWidth + j;
					if (emptyScreen[index] != buildingSymbol)
					{
						emptyScreen[index] = blankSpace;
					}
				}
			}
		}
	}
	return emptyScreen;
}
