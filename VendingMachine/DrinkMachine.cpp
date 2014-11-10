//DrinkMachine.cpp
//class declaration
#include "stdafx.h"
#include "DrinkMachine.h"

DrinkMachine::DrinkMachine(){
	drinkData[0] = { "Cola", 1.00, 20 };
	drinkData[1] = { "Root beer", 1.00, 20 };
	drinkData[2] = { "Orange soda", 1.00, 20 };
	drinkData[3] = { "Grape Soda", 1.00, 20 };
	drinkData[4] = { "Bottled water", 1.50, 20 };
}

DrinkMachine::~DrinkMachine(){
	dailyReport();
}

void DrinkMachine::displayChoices(){
	for (int i = 0; i < 5; i++){
		cout << left << i + 1 << "-  " << setw(15) << drinkData[i].drinkName;
		cout << right << setw(5) << setprecision(2) << fixed << drinkData[i].price << setw(10) << drinkData[i].available << endl;
	}

}

void DrinkMachine::buyDrink(int choice){
	double money;
	int finalize;

	money = inputMoney(choice);

	cout << "Press 1 to finalize your transaction, or press 0 to refund your money.\n";

	finalize = getChoice(0, 1);

	if (finalize == 1){
		if (drinkData[choice].available == 0){
			cout << "This drink is sold out!\n";
			cout << "Your $" << money << " has been returned.\n";
		}
		else{
			if (money >= drinkData[choice].price){
				drinkData[choice].available--;
				cout << "Enjoy your beverage.\n";
				if (money > drinkData[choice].price){
					cout << "Your change is $" << money - drinkData[choice].price << endl;
				}
			}
			else if (money < drinkData[choice].price){
				cout << "You did not enter enough money for this beverage.\n";
				cout << "Your $" << money << " has been returned.\n Try again.\n";
				money = inputMoney(choice);
			}
		}

	}else if(finalize == 0){
		cout << "Your $" << money << " has been returned.\n";
	}


}

double DrinkMachine::inputMoney(int choice){
	double money;
	int entry;
	bool valid = true;
	entry = choice - 1;
	cout << "Please enter your money\n";
	cin >> money;
	if (!cin) {
		cout << "Your input was not a valid number. I hope your not trying to hack my man\n";
		cin.clear();
		fflush(stdin);
		buyDrink(choice);
	}
	
	return money;
}

int DrinkMachine::getChoice(int min, int max)
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

void DrinkMachine::dailyReport(){
	double total = 0;
	int drinks;
	cout << "At the end of the day, there are \n";
	for (int i = 0; i < 5; i++){
		cout << drinkData[i].available << " " << drinkData[i].drinkName << "s left.\n";
		drinks = 20 - drinkData[i].available;
		total = total + (drinks * drinkData[i].price);
	}
	cout << "$" << total << " was earned.\n";
}