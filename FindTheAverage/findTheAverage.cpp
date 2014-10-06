 // This program finds the average number of boxes of cookies 
// sold by the children in a particular scout troop. 
// It illustrates the use of a counter, an accumulator, 
// and an end sentinel.
// Chris Sorrell
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{   
   int numBoxes,         // Number of boxes of cookies sold by one child
       totalBoxes,       // Accumulates total boxes sold by the entire troop
       numSeller;        // Counts the number of children selling cookies
       
   double averageBoxes;  // Average number of boxes sold per child
   
   totalBoxes = 0;
   numSeller = 1;
   
   cout << "             **** Cookie Sales Information **** \n\n";
   
   // Get the first input
   cout << "Enter number of boxes of cookies sold by seller " << numSeller
        << " (or -1 to quit): ";
   cin  >> numBoxes;
   
   // LOOPS WHILE numBoxes
   // IS NOT EQUAL TO -1, THE SENTINEL VALUE.
   while (numBoxes != -1)
   {
	   if (numBoxes > -1)
	   {
		   // WRITE CODE TO ADD numBoxes TO THE totalBoxes ACCUMULATOR.
		   totalBoxes = numBoxes + totalBoxes;
		   // WRITE CODE TO ADD 1 TO THE numSeller COUNTER.
		   numSeller++;
	   }
	
      
   
	   cout << "Enter number of boxes of cookies sold by seller " << numSeller
		   << " (or -1 to quit): ";
	   cin >> numBoxes;
	   
   }
   // WHEN THE LOOP IS EXITED, THE VALUE STORED IN THE numSeller COUNTER
   // IS ONE MORE THAN THE ACTUAL NUMBER OF SELLERS. 
   // TO ADJUST IT TO THE ACTUAL NUMBER OF SELLERS.
   numSeller--;
   
   if (numSeller == 0)
      cout << "\nNo boxes were sold.\n";
   else
   { 
   	   averageBoxes = totalBoxes / (double)numSeller;
	   cout << "There are " << numSeller << " sellers, and the average number of boxes sold is " << averageBoxes << " per seller. \n";
   }
   
   return 0;
}
