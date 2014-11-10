//This program accepts a user inputted string, converts the first lettor of each word to uppercase through the properWords() funciton,
//and also converts each letter to uppercase using the uppercase() function. 
#include "stdafx.h"
#include <iostream>
#include <string>
#include "CharConverter.h"



using namespace std;

int main(){
	string input;
	string choice;

	bool getChoice(char);

	CharConverter newInput; 

	do{
		cout << "Please enter a sentence.\n";
		getline(cin, input);

	    cout << newInput.properWords(input) << endl;
	
	    cout << newInput.uppercase(input) << endl;
		cout << "Would you like to do that again?\n";
		
		getline(cin, choice);
		/*the string vs. char input tripped me up for a while. When choice was a char variable, 
		the \n in the input buffer would cause the program to skip the sentence input after the first iteration. 
		This is why I made choice a string variable*/
	} while (getChoice(choice[0]) == true);
	
	return 0;
}

/*getChoice function*/
bool getChoice(char choice){	
	if (choice == 'Y' || choice == 'y'){
		return true;
	}
	else{
		return false;
	}
}
