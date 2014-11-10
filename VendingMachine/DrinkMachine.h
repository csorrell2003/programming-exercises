//DrinkMachine.h
//class declaration
#ifndef DRINKMACHINE_H
#define DRINKMACHINE_H
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class DrinkMachine{
	struct Drink
	{
		string drinkName;
		double price;
		int available;
	};

private:
	Drink drinkData[5];
	double inputMoney(int);
	void dailyReport();

public:
	DrinkMachine();
	~DrinkMachine();
	int getChoice(int min, int max);
	void displayChoices();
	void buyDrink(int);

};

#endif