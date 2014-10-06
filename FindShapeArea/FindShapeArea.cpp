// This program calculates the area of different shapes, based on the users input 
// Chris Sorrell
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu();
double findSquareArea();
double findCircleArea();
double findTriangleArea();

double area;
int getChoice(int min, int max);

const double PI = 3.14159;

int main()
{
	int choice;

	do{
		displayMenu();

		choice = getChoice(1, 4);

		if (choice == 1)
		{
			cout << "The area of your square is " << findSquareArea() << endl << endl;
		}
		else if (choice == 2)
		{
			cout << "The area of your circle is " << findCircleArea() << endl << endl;
		}
		else if (choice == 3)
		{
			cout << "The area of your right triangle is " << findTriangleArea() << endl << endl;
		}
		else if (choice == 4)
		{
			exit(0);
		}

	} while (choice != 4);

	return 0;
}
//**** Display Menu Function ***
void displayMenu()
{

	cout << "Please select a shape from the menu below. \n";
	cout << "1--square \n";
	cout << "2--circle \n";
	cout << "3--right triangle \n";
	cout << "4--exit \n";


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


//**** findSquareArea Function ***
double findSquareArea()
{
	double square_width;

	cout << "What is the square's width? \n";
	cin >> square_width;
	return square_width * square_width;
}

//**** findCircleArea Function ***
double findCircleArea()
{
	double circle_radius;


	cout << "What is the circle's radius? \n";
	cin >> circle_radius;
	return PI * (circle_radius * circle_radius);
}

//**** findTriangleArea Function ***
double findTriangleArea()
{
	double triangle_height,
		triangle_width;

	cout << "What is the triangle's width? \n";
	cin >> triangle_width;
	cout << "What is the triangle's height? \n";
	cin >> triangle_height;
	return (triangle_height * triangle_width) / 2;
}
