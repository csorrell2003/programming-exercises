#include "stdafx.h"
#include "TicketManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

TicketManager::TicketManager() {

	std::ifstream SeatPrices;
	std::ifstream SeatAvailability;

	// open data files
	SeatPrices.open("SeatPrices.dat");
	SeatAvailability.open("SeatAvailability.dat");

	if (!SeatAvailability.is_open() || !SeatPrices.is_open()) {
		std::cout << "The data files failed to open. Make sure the files have been added to the correct project directory.";
	}
	else {
		// this block steps through the seatStructure array to set the 
		// 'price' and 'available' variables as they are read from the
		//  dat files
		for (int i = 0; i < 15; i++)
		{
			SeatPrices >> price;
			for (int j = 0; j < 30; j++){
				SeatAvailability >> availability;
				seatStructure[i][j] = SeatStructure{ price, availability };
			}
		}
	}
	SeatPrices.close();//close the files
	SeatAvailability.close();

}

TicketManager::~TicketManager(){
	std::ofstream SeatAvailability;
	//open data file
	SeatAvailability.open("SeatAvailability.dat");

	if (!SeatAvailability.is_open()){
		std::cout << "The data files failed to open. Make sure the files have been added to the correct project directory.";
	}
	else{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 30; j++){
				SeatAvailability << seatStructure[i][j].available; //write updated availability data to the dat file
			}
			SeatAvailability << "\n"; //puts the new line at the end of each row
		}
	}
	SeatAvailability.close(); //close the file

}

std::string TicketManager::displaySeats(){
	//displays the chart to show available seats
	std::stringstream seatStr;
	seatStr << "         Seats\n";
	seatStr << std::setw(40) << std::right << "012345678901234567890123456789\n";
	for (int i = 1; i <= 15; i++){
		seatStr << "Row " << std::setw(3) << std::left << i << "  ";
		for (int j = 0; j < 30; j++){
			seatStr << std::setw(1) << std::left << seatStructure[i - 1][j].available;
		}
		seatStr << "\n";
	}

	return seatStr.str();
}

/**
* Creates and returns a string holding a report that tells
* how many seats have been sold, are still available, and
* how much money has been collected.
* @return string holding the report
*/
std::string TicketManager::report() {
	std::stringstream reportStr;
	int seatsAvailable = 0;
	float moneyCollected = 0;

	// Determine seats available and money collected
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 30; j++) {
			if (seatStructure[i][j].available == '#') {
				seatsAvailable++;
			}
			else {
				moneyCollected += seatStructure[i][j].price;
			}
		}
	}

	reportStr << "\n--------- Report ---------\n";
	reportStr << std::setw(18) << std::left << "Seats Sold: " << std::setw(8) << std::right << 450 - seatsAvailable << "\n";
	reportStr << std::setw(18) << std::left << "Seats Available: " << std::setw(8) << std::right << seatsAvailable << "\n";
	reportStr << std::setw(18) << std::left << "Money Collected: $" << std::setw(8) << std::right << std::fixed << std::setprecision(2) << moneyCollected << "\n";

	return reportStr.str();
}


/* This function handles the ticket request.
If the request is sucessful, a string message
is returned that lists the number of seats requested,
the seat price, and the total cost. If any of the
seats are unavailable or do not exist, a string
message is returned to explain the failure */
std::string TicketManager::requestSeats(int numSeats, int numRow, int numSeatStart){
	total = 0;
	for (int i = 0; i < numSeats; i++){
		total = total + seatStructure[numRow - 1][numSeatStart + i].price;
		if ((seatStructure[numRow - 1][numSeatStart + i].available == '*') || ((numSeatStart + i) > 30)){
			requestAvailable = false;
			return "One or more of the seats you requested is not available.";
		}
	}

	//requestAvailable is handled within a client program conditional.
	requestAvailable = true;

	std::stringstream requestStr;
	requestStr << "You requested " << numSeats << " seats in row " << numRow << ".\n";
	requestStr << "The seats cost $" << std::fixed << std::setprecision(2) << seatStructure[numRow - 1][numSeatStart].price;
	requestStr << " each. Your total is $" << std::fixed << std::setprecision(2) << total << ".\n";
	return requestStr.str();


}

std::string TicketManager::purchaseSeats(int numSeats, int numRow, int numSeatStart) {
	std::cout << "Please tender $" << std::fixed << std::setprecision(2) << total << ": ";
	int money = inputMoney();
	while (money < total) {
		std::cout << "Not enough cash, please tender $" << std::fixed << std::setprecision(2) << total << ": ";
	}

	// Seats have been sold, mark then as sold
	for (int i = 0; i < numSeats; i++){
		seatStructure[numRow - 1][numSeatStart + i].available = '*';
	}

	// Print tickets
	std::stringstream ticketStr;
	ticketStr << "TICKETS\n";
	for (int i = 0; i < numSeats; i++){
		ticketStr << "-------------------------------\n";
		SeatStructure currSeat = seatStructure[numRow - 1][numSeatStart + i];
		ticketStr << std::left << std::setw(10) << "| Row" << std::left << std::setw(10) << "| Seat" << std::left << std::setw(9) << "| Price" << " |\n";
		ticketStr << "| " << std::left << std::setw(8) << numRow << "| " << std::left << std::setw(8) << numSeatStart + i << "| " << "$" << std::left << std::setw(6) << std::fixed << std::setprecision(2) << currSeat.price << " |\n";
		ticketStr << "-------------------------------\n\n";
	}

	if (money > total){
		ticketStr << "Your change is $" << money - total << "\n";
	}


	return ticketStr.str();
}


float TicketManager::inputMoney() {
	float input;
	std::cin >> input;
	return input;
}