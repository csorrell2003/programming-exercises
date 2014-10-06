// This program calculates the distance traveled per hour based on the users input
// Chris Sorrell
#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int mph = 0,
		hours = 0,
		i = 1,
		distance;

	while (mph < 1)
	{
		cout << "What is the speed of the vehicle in mpg? \n";
		cin >> mph;
	}

	while (hours < 1)
	{
		cout << "How many hours has the vehicle been traveling? \n";
		cin >> hours;
		cout << endl << endl;
	}

	cout << left << " Hour";
	cout << right << setw(20) << "Miles Traveled" << endl;
	cout << "--------------------------" << endl << endl;

	while (i <= hours)
	{
		distance = mph * i;
		cout << "  " << i;
		cout << right << setw(17) << distance << endl;
		i++;
	}

	cout << endl << endl;
	
   
   return 0;
}
   