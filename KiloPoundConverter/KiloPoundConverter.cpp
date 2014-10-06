// Lab 6 kiloConverter.cpp 
// This menu-driven program lets the user convert 
// pounds to kilograms and kilograms to pounds.
// Chris Sorrell
#include "stdafx.h" 
#include <iostream>
using namespace std;

// Function prototypes

void displayMenu();
int getChoice(int, int);
void kilosToPounds();
void poundsToKilos();

/*****     main     *****/
int main()
{
	int choice;

	
		displayMenu();
		choice = getChoice(1, 3);

		if (choice == 1)
			kilosToPounds();
		else if (choice == 2)
			poundsToKilos();
		else
			exit(0);
	

	return 0;
}

/*****     displayMenu     *****/
void displayMenu()
{
	cout << "1. Convert kilograms to pounds \n";
	cout << "2. Convert pounds to kilograms \n";
	cout << "3. Quit \n";
}

/*****     getChoice     *****/
int getChoice(int min, int max)
{
	int input;

	// Get and validate the input
	cin >> input;
	while (input < min || input > max)
	{
		cout << "Invalid input. Enter an integer between " << min << " and " << max << ": ";
		cin >> input;
	}
	return input;
}


/*****     kilosToPounds     *****/

void kilosToPounds()
{
	double weight,
		output;
	cout << "Kilos to be converted: \n";
	cin >> weight;
	output = weight * 2.2;
	cout << weight << " kilograms = " << output << " pounds. \n\n";
}

/*****    poundsToKilos     *****/
void poundsToKilos()
{
	double weight,
		output;
	cout << "Pounds to be converted: \n";
	cin >> weight;
	output = weight / 2.2;
	cout << weight << " pounds = " << output << " kilograms. \n\n";
}
