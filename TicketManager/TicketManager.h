//TicketManager
#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H
#include <string>
#include <iostream>

class TicketManager {
private:
	struct SeatStructure
	{
		float price;
		char  available;
	};

	float inputMoney();
	float total;
	char availability;
	float price;
	SeatStructure seatStructure[15][30];

public:
	TicketManager();
	~TicketManager();
	std::string displaySeats();
	std::string requestSeats(int numSeats, int numRow, int numSeatStart);
	std::string purchaseSeats(int numSeats, int numRow, int numSeatStart);
	std::string report();

	bool requestAvailable;

};

#endif