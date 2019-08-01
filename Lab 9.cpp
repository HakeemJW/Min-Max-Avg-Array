// C++ Program			Lab 09.cpp
// Course				CSE1311/W01
// Name:				Hakeem Wilson
// Assignment #:		Lab 9 
// Due Date:			3/31/2019

/* The purpose of this program is to generate a consistent set of random numbers into an array,
   then use functions to find the higest and lowest value as well as their respective postions,
   then find the average of the array, and finally print a table showing all postions in the aray,
   as well as their difference from the average.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

//Declaration of array and size
double average, arrayavg, m;
int value[25] = { 0 };

void fillarray()
{
	//Entering 25 random numbers into the array
	for (int i = 0; i < 25; i++)
	{
		value[i] = rand() % 100 + 1;
	}
}

//Function used to print the values in the array
void printarray(int value[], int size)
{
	for (int i = 0; i < 25; ++i)
	{
		cout << "Value -" << "\t" << value[i] << endl;
	}
}

//Function to calculate maximum value
void maxvalue(int value[], int size)
{
	int max = value[0];	 	 //set max to the first position in the array
	int saveHigh = 0;		//save the position of the highest so far

	for (int i = 1; i < 25; ++i) 	//start at 1 since the first value is already in max    
	{
		if (value[i] > max)	      	 //if a particular score is higher than the one in max
		{
			max = value[i];     	//put that score in max and keep going
			saveHigh = i;		//place the index of the higher score in saveHigh
		}
	}
	cout << "The highest of the values is " << max << endl;
	cout << "The position in the array of the highest number is " << saveHigh << endl;
}

//Function to calculate minimum value
void minvalue(int value[], int size)
{
	int min = value[0];	 	 //set min to the first position in the array
	int saveLow = 0;		//save the position of the lowest so far

	for (int i = 1; i < 25; ++i) 	//start at 1 since the first value is already in min    
	{
		if (value[i] < min)	      	 //if a particular score is lower than the one in min
		{
			min = value[i];     	//put that score in min and keep going
			saveLow = i;		//place the index of the lower score in saveLow
		}
	}
	cout << "The lowest of the values is " << min << endl;
	cout << "The position in the array of the lowest number is " << saveLow << endl;
}

//Function to calculate the average
double avg(int value[], int size)
{
	int total = 0;
	double average;

	for (int i = 0; i < 25; ++i)    //notice the loop starts at 0 and goes to less than the last element
	{
		total += value[i];
	}
	average = (double)total / 25; cout << "The average of the values is " << average << endl;

	return average;
}

void printtable(int value[], int size)
{
	int position = 0;
	for (int i = 0; i < 25; ++i)    //notice the loop starts at 0 and goes to less than the last element
	{
		cout << endl;
		cout << "Position" << "\t\t" << "Value" << "\t\t" << "Difference from Average" << endl;
		cout << position << "\t\t\t" << value[i] << "\t\t" << (value[i] - m) << endl;
		cout << endl;
		++position;
	}
}

//Start of Main
int main()
{
	fillarray();
	m = avg(value, 25); //Calls to avg function
	printtable(value, 25);
	cout << endl;
	maxvalue(value, 25);		//Calls to maxvalue functionn
	cout << endl;
	minvalue(value, 25);	//Calls to minvalue function
	cout << endl;
	cout << "This program was coded by Hakeem Wilson" << endl;
	system("PAUSE");
	return 0;
}
