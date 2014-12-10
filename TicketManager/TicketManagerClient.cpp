// TicketManagerClient.cpp - The frontend client for the TicketManager class.
// Allows a user to interface with the ticket manger to display the seating
// chart, request tickets, and print sales reports.

// Includes
#include "stdafx.h"
#include <iostream>
#include <string>
#include "TicketManager.h"

// Namespace
using namespace std;

// Function Prototypes
void displayMenu();
int  getChoice(int, int);

// Constants
const int MENU_CHOICES = 4;

// Main Program
int main()
{
	TicketManager ticketManager;
	bool running = true;
	int numSeats, numRow, numSteatStart;
	string purchaseConfirm;


	while (running) {
		// Display the menu
		displayMenu();

		// Get the users menu choice
		switch (getChoice(1, MENU_CHOICES)) {

			// Menu Option 1 - display seating chart
		case 1:
			cout << ticketManager.displaySeats();
			break;

			// Menu Option 2 - request tickets
		case 2:
			// Request # of seats, row #, and starting seat #
			cout << "How many seats would you like?\n";
			numSeats = getChoice(1, 30);
			cout << "What is your preferred row number.\n";
			numRow = getChoice(1, 15);
			cout << "Enter the starting seat number.\n";
			numSteatStart = getChoice(1, 30);

			// Request the seats
			cout << ticketManager.requestSeats(numSeats, numRow, numSteatStart);

			// Find out if the user wants the seats
			if (ticketManager.requestAvailable == true){
				cout << "Do you want to purchase these seats (y or n)? ";
				cin >> purchaseConfirm;

				// If they do, purchase them
				if (purchaseConfirm == "y" || purchaseConfirm == "Y") {
					// Purchases the seats and prints the tickets
					cout << "Requested Tickets: \n";
					cout << ticketManager.purchaseSeats(numSeats, numRow, numSteatStart);
				}

				else {
					cout << "Purchase Aborted";
				}
			}
			break;

			// Menu Option 3 - print a sales report
		case 3:
			cout << ticketManager.report();
			break;

			// Menu Option 4 - exit the program
		case 4:
			running = false;
			break;

			// Undefined behavior, should never occur
		default:
			running = false;
		}
	}

	return 0;
}

/**
* Displays the choices available to the user.
*/
void displayMenu()
{
	cout << "\n\n MENU \n\n";
	cout << "1) Display the seating chart\n";
	cout << "2) Request tickets\n";
	cout << "3) Print a sales report\n";
	cout << "4) Exit program\n";
	cout << "Enter your choice: ";
}

/**
* Gets an integer from the user and validates it lies between
* the specified minimum and maximum values.
* @param  min The minimum value the user can enter
* @param  max The maximum value the user can enter
* @return The user's ultimate choice
*/
int getChoice(int min, int max)
{
	int input;

	// Get and validate the input
	cin >> input;

	while (input < min || input > max) {
		cout << "Invalid input. Enter an integer between "
			<< min << " and " << max << ": ";
		cin >> input;
	}
	return input;
}