//Median function
//This function finds the median number of a sorted array of integers. 
//if the array size is even, the median is set to the average of the 2 middle numbers
#include "stdafx.h"
#include <iostream>

double medianFunction(int *array, int size){
	double median;
	if (size % 2 == 0){
		size = size / 2;
		median = (double)(*(array + size) + *(array + (size - 1))) / 2.0;
	}
	else{
		//size divided by 2 is the middle number since the array count actually starts at 0.
		size = (size) / 2;
		median = *(array+size); 
	}
	return median;
}
//test run
int main(){
	int list1[] = { 2, 5, 6, 7, 11, 65 };
	int *plist1 = list1;

	std::cout << "Even list median: ";
	std::cout << medianFunction(plist1, 6)<< std::endl;
	
	int list2[] = { 5, 9, 11, 15, 19, 65, 77};
	int *plist2 = list2;

	std::cout << "Odd list median: ";
	std::cout << medianFunction(plist2, 7) << std::endl;


	return 0;
}
