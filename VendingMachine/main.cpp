//This program acts as a vending machine simulator. It keeps a count of how many beverages are available, makes them available for 'purchase',
//accepts payment, and returns a count of how much $ was earned at the end of the program. 
#include "stdafx.h"
#include "DrinkMachine.h"
#include <iomanip>

using namespace std;

int main(){
	int choice;

	DrinkMachine drink;
	do{
		drink.displayChoices();
		cout << "Use the numbered options to select which drink you would you like to buy.\n Or press 6 to exit. \n";
		choice = drink.getChoice(1, 6);

		if (choice > 0 && choice < 6)
		{
			choice--;
			drink.buyDrink(choice);
		}
		else if (choice == 6)
		{
			drink.~DrinkMachine();
			exit(0);
		}
	} while (choice != 6);


	return 0;
}
