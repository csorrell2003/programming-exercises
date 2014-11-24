//this program finds the average test score based on the user generated list of scores using pointer notation 
#include "stdafx.h"
#include <iostream>

using namespace std;

int main(){
	int getNumber();
	void setScores(int *array, int);
	void sortArray(int *array, int);
	int findAverage(int *array, int);

    int numberOfScores = getNumber();
	int *ptr = 0;
	int average;
	ptr = new int[numberOfScores]; //allocate the array

	setScores(ptr, numberOfScores); //call setScores
	average = findAverage(ptr, numberOfScores); //call findAverage
	sortArray(ptr, numberOfScores); //call sortArray
	
	cout <<  endl << endl;
	cout << "Sorted list of scores:\n";
	for (int i = 0; i < numberOfScores; i++){
		cout << *(ptr + i);
		if (i != numberOfScores - 1){
			cout << ", ";
		}
	}
	cout << "\n\nAverage score:\n" << average << endl << endl;

	return 0;
}

/*getNumber function*/
int getNumber(){
	int number;
	do{
		cout << "Enter the total number to test scores. \n";
		cin >> number;
	} while (number < 1);

	return number;
}


/*setScores function*/
void setScores(int *array, int size){
	for (int i = 0; i < size; i++){
		cout << "Enter score number " << i + 1 << endl;
		cin >> *(array+ i);
	}
}

/*sortArray function*/
void sortArray(int *array, int size){
	int start, minIndex, minValue;
	for (start = 0; start < (size - 1); start++){
		minIndex = start;
		minValue = *(array+start);

		for (int i = start + 1; i < size; i++){
			if (*(array+i) < minValue){
				minValue = *(array+i);
				minIndex = i;
			}
		}
		*(array+minIndex) = *(array+start);
		*(array+start) = minValue;
	}
}

/*findAverage function*/
int findAverage(int *array, int size){
	int total = 0;
	int average;
	for (int i = 0; i < size; i++){
		total = total + *(array + i);
	}
	average = total / size;
	return average;
}

