#include <iostream>
#include "ConsoleShape.h"

using namespace std;
const int SCREEN_WIDTH = 120; //console screen width
const int SCREEN_HEIGHT = 29; //console screen height - 1 line for system pause
const char blankSpace = '-'; //the symbol used to fill the void in the label
const char builder = '*'; // the symbol used to draw
const int lowestValidN = 3; 
const int highestValidN = 9999;

//function used to read and validate input
void validateInput(int& input)
{
	while (!(cin >> input) || input < lowestValidN || input > highestValidN || input % 2 == 0)
	{
		cout << "Invalid input. Enter n: ";
		cin.clear();
		cin.ignore(SCREEN_WIDTH, '\n');
	}
}
int main() {
	int n = 0;
	cout << "Enter n: ";
	validateInput(n);
	char* consoleScreen = new char[SCREEN_HEIGHT*SCREEN_WIDTH]; // work screen as normal array

	ConsoleShape mm(n);
	//Adding all the points that create the MM label
	mm.addPoint(ConsolePoint(0, n));
	mm.addPoint(ConsolePoint(n, 0));
	mm.addPoint(ConsolePoint(2 * n, n));
	mm.addPoint(ConsolePoint(3 * n, 0));
	mm.addPoint(ConsolePoint(4 * n, n));
	mm.addPoint(ConsolePoint(5 * n, n));
	mm.addPoint(ConsolePoint(6 * n, 0));
	mm.addPoint(ConsolePoint(7 * n, n));
	mm.addPoint(ConsolePoint(8 * n, 0));
	mm.addPoint(ConsolePoint(9 * n, n));
	//----------------------------------------------

	system("cls");//clear console screen
	consoleScreen = mm.drawShape(SCREEN_WIDTH, SCREEN_HEIGHT, builder, blankSpace, consoleScreen);//draw
	//output final screen
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			cout << consoleScreen[i*SCREEN_WIDTH + j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
