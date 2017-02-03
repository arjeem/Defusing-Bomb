// DefusingBomb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

/* Assign colors for readability */
#define WHITE 0
#define RED 1
#define ORANGE 2
#define BLACK 3
#define GREEN 4

using namespace std;

int main()
{
	bool defused = false;
	int result, state = 0, wireColor = 6;

	/*	Matrix to represent Finite Stae Machine
		Rows = State
		Columns = Wire Colors (White, Red, Orange, Black, Green) 
		-1 = wrong choice
		6 = defused
		0-5 = Next State*/

	int fsm[6][5] = { 1, 2,-1,-1,-1,
					2,-1,3,-1,-1,
					-1,0,-1,3,-1,
					-1,-1,4,3,5,
					-1,-1,-1,-1,6,
					-1,-1,6,-1,-1 };

	string color;
	ifstream infile("SampleInput2.txt");

	while (infile >> color)
	{
		if (!color.compare("white"))
			wireColor = WHITE;
		else if (!color.compare("red"))
			wireColor = RED;
		else if (!color.compare("orange"))
			wireColor = ORANGE;
		else if (!color.compare("black"))
			wireColor = BLACK;
		else if (!color.compare("green"))
			wireColor = GREEN;
		else
		{
			cout << "Invalid wire color detected. Exiting." << endl;
			return 0;
		}

		result = fsm[state][wireColor];

		switch (result) {
			case 6:
				cout << "Bomb defused!" << endl;
				getchar();
				return 0;
				break;
			case -1: 
				cout << "BOOM!" << endl;
				getchar();
				return 0;
				break;
			default:
				state = result;
				cout << "ok" << endl;
				break;
		}
	}
	cout << "BOOM!" << endl;
	getchar();

}