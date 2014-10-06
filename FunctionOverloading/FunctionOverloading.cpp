// This program illustrates an example of function overloading
// Total cost of medical treatment is calulated based on user input
// Chris Sorrell
#include "stdafx.h"
#include <iostream>
using namespace std;

// Function prototypes
void displayMenu();
int getChoice(int min, int max);
void isInPatient();
void isOutPatient();
double calculateCharges(int, double, double);
double calculateCharges(double, double);

/*****     main     *****/
int main()
{
   // main variables
	int choice;

	
		displayMenu();
		choice = getChoice(1, 3);

		if (choice == 1)
			isInPatient();
		else if (choice == 2)
			isOutPatient();
		else if (choice == 3)
			exit(0);
	
     
   return 0;
}

/*****     displayMenu     *****/
void displayMenu()
{
	cout << "Were you admitted as an in-patient or an out-patient? \n";
	cout << "1. in-patient \n";
	cout << "2. out-patient \n";
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


/*****    isInPatient      *****/
void isInPatient()
{
	int days;
	double dailyRate,
		serviceCharges;
	cout << "How many days did you spend in the hospital?\n";
	cin >> days;
	cout << "\nWhat is the daily rate for a hospital stay?\n";
	cin >> dailyRate;
	cout << "\nWhat are the total charges for other hospital services? (lab tests, etc.)\n";
	cin >> serviceCharges;

	cout << "The total cost is $" << calculateCharges(days, dailyRate, serviceCharges) << endl;

}

/*****    isOutPatient      *****/
void isOutPatient()
{
	double serviceCharges,
		medicationCost;

	cout << "What is the cost of your hospital services? (lab tests, etc.)\n";
	cin >> serviceCharges;
	cout << "\nWhat are the hospital medication charges\n";
	cin >> medicationCost;

	cout << "The total cost is $" << calculateCharges(serviceCharges, medicationCost) << endl;
}

/*****    calculateCharges      *****/
double calculateCharges(int days, double dailyRate, double serviceCharges)
{
	double totalCharges;

	totalCharges = (days * dailyRate) + serviceCharges;
	return totalCharges;
}

double calculateCharges(double serviceCharges, double medicationCharges)
{
	double totalCharges;

	totalCharges = medicationCharges + serviceCharges;
	return totalCharges;
}