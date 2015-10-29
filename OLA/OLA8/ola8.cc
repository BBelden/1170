//Name:       Ben Belden
//Section:    CSCI 1170-001
//Assignment: Open Lab Assignment #8
//Due:        23:59, December 4, 2012
//Purpose:    The purpose of this program will be to read in data from a 
//			  file and put it into an Array and then work with the data 
//			  that is in the Array.
          

#include <iostream>		//for cin/cout
#include <fstream>		//for input/output files
#include <iomanip>		//for setw()
#include <math.h>		//for pow and sqrt
#include <cstdlib>  	//for srand


using namespace std;

//global variable declarations
const int MAX_TEMPS = 25;
int temps[MAX_TEMPS];
ifstream inFile; 
int numTemps, sum;
float average;

//function prototypes
void OpenInFile (ifstream&);
void ZeroOut (int temps[]);
void FillArray (ifstream&, int temps[], int&, int);
void DisplayArray (const int temps[]);
void SumAverage (const int temps[], int, int&, float&);
float StandardDeviation (const int temps[], int, float);
void Random (const int temps[], int);
void Sort (int temps[], int);
int Highest (const int temps[], const int);
int Lowest (const int temps[]);

//main function
int main ()
{	
	//cout << fixed /*<< setprecision(6)*/;
	
	OpenInFile (inFile);
	
	//test for successful open of input file
	if (!inFile)
	{
		cout << "Unable to open input file.\n";
		return 1;
	}
	
	ZeroOut (temps);
	FillArray (inFile, temps, numTemps, MAX_TEMPS);
	cout << endl;
	DisplayArray (temps);
	
	
	SumAverage (temps, numTemps, sum, average);
	
	cout << "\nThe standard deviation of all the input data is: " << endl;
	cout << StandardDeviation (temps, numTemps, average) << endl;
	
	Random (temps, numTemps);
	
	Sort (temps, numTemps);
	
	cout << "\nThe highest integer of the input data is: ";
	cout << Highest (temps, numTemps) << endl;
	cout << "\nThe lowest integer of the input data is: ";
	cout << Lowest (temps) << endl << endl;
	
	
	DisplayArray (temps);

	cout << endl;
	
	inFile.close ();
	
	return 0;	
}

//user defined functions
//*********************************************************************************

void OpenInFile (ifstream& inFile)
//prompts the user to input the file name containing client data
{
	string inFileName;
	cout << "Please enter the name of the input file: \n";
	cin >> inFileName;
	inFile.open (inFileName.c_str());
}

//*********************************************************************************

void ZeroOut (int temps[])
//zeroes out the array
{
	for (int i = 0; i < MAX_TEMPS; i++)
		temps[i] = 0;
}


//*********************************************************************************

void FillArray (ifstream& inFile, int temps[], int& numTemps, int MAX_TEMPS)
//populates the array with input file data
{
	numTemps = 0;
	
	while (numTemps < MAX_TEMPS && inFile >> temps[numTemps])
	{	
		//cout << numTemps << "\t" << temps[numTemps] << endl;
		numTemps++;
	}
}
//*********************************************************************************
	
void DisplayArray (const int temps[])
//displays each element of the array in a column
{

	for (int i = 0; i < MAX_TEMPS; i++)
		cout << temps[i] << endl;
}
	
//*********************************************************************************

void SumAverage (const int temps[], int numTemps, int& sum, float& average)
//calculates the sum and average of all of the input data
{

	sum = 0; 
	for (int i = 0; i <= numTemps; i++)
		sum += temps[i];
	average = (float) sum / (numTemps);
	
	cout << "\nThe sum of all the input data is: " << sum << endl;
	cout << "\nThe average of all the input data is: " << average << endl;

}

//*********************************************************************************

float StandardDeviation (const int temps[], int numTemps, float average)
//calculates the standard deviation of all of the input data
{
	float dev; 
	float dSum = 0;
	for (int i = 0; i < numTemps; i++)
		dSum += pow((temps[i]-average),2);
	dev = sqrt (dSum/(numTemps-1));
	return dev; 
}

//*********************************************************************************

void Random (const int temps[], int numTemps)
//chooses a random element within the array and prints the data within that element
{
	srand((unsigned)time(0));
	int randInt = (rand()%(numTemps));
	cout << "\nThe data in randomly chosen cell " << randInt << " is: " << temps [randInt] << endl;	
}

//*********************************************************************************

void Sort (int temps[], int numTemps)
//sorts the array from lowest to highest value
{
	int hold, count, search, min;
	
	for (count = 0; count < numTemps - 1; count++)
	{
		min = count;
		for (search = count + 1; search < numTemps; search++)
			if (temps[search] < temps[min])
				min = search;
		hold = temps[min];
		temps[min] = temps[count];
		temps[count] = hold;
		
	}
}

//*********************************************************************************

int Highest (const int temps[], int numTemps)
//returns the highest integer from the array after sorting
{
	int highest = temps[numTemps - 1];
	return highest;
}

//*********************************************************************************

int Lowest (const int temps[])
//returns the lowest integet from the array after sorting
{
	int lowest = temps[0];
	return lowest;
}
//*********************************************************************************
