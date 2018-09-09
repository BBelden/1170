//Name:       Ben Belden
//Section:    CSCI 1170-001
//Assignment: Open Lab Assignment #7
//Due:        23:59, November 16, 2012
//Purpose:    To produce customer bills based on given input data.
//            Prompts the user to provide a filename containing
//            client data. Program will process the data and then
//            open output files with the name of the individual
//            client and then print a bill in the output file.

#include <iostream>
#include <string>		
#include <fstream>		//for input/output files
#include <iomanip>		//for setw()
#include <math.h>		//for floorf
#include <cstdlib>  	//for executing terminal commands
#include <cstdio>		// for executing terminal commands


using namespace std;

//function prototypes
void OpenInFile (ifstream&);
void GenerateBill (ofstream&, string&, string&, string&);
void Name (ifstream&, string&, string&, string&);
void GetInfo (ifstream&, int&, int&, char&, char&, string&, float&);
int OpenOutFile (ofstream&, string&, string&, string&);
void Dashes (ofstream&);
void FoodCost (int&, int&, char&, float&, float&, float&, float&, string&);
void HallCost (char&, string&, float&, float&);
void Total (float&, float&, float&, float&, float&, float&, float&, float&, float&);
void PrintBill (ofstream&);

//global variable declarations
ifstream inFile; 
ofstream outFile;
int adults, kids;
char hall, type;
string day, first, last, name, mealType;
float aMeal, kMeal, deposit, discount, grTotal, mTotal, rate, room, surcharge, tax, total, rDiscount;

//main function
int main ()
{	
	OpenInFile (inFile);
	
	//test for successful open of input file
	if (!inFile)
	{
		cout << "Unable to open input file.\n";
		return 1;
	}
	
	//GenerateBill (outFile, name, first, last);
	while (inFile)
		GenerateBill (outFile, name, first, last);
	
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

void GenerateBill (ofstream& outFile, string& name, string& first, string& last)
// runs all of the user-defined functions
{
	Name (inFile, first, last, name);
	GetInfo (inFile, adults, kids, type, hall, day, deposit);
	OpenOutFile (outFile, first, last, name);
	FoodCost (adults, kids, type, mTotal, tax, aMeal, kMeal, mealType);
	HallCost (hall, day, surcharge, room);
	Total (mTotal, tax, room, surcharge, deposit, total, grTotal, rate, rDiscount);
	PrintBill (outFile);
	outFile.close ();
		
	cout << "\nBill generated for " << name << " in file: " << endl;
	cout << first + last << ".dat\n";
	cout << "in directory: " << endl;

	// for executing terminal command: pwd
	char pwd[10];		
	sprintf(pwd, "pwd");
	system(pwd);
}

//*********************************************************************************

void Dashes (ofstream& outFile)
//print a line of dashes
{
	for (int d = 1; d < 50; d++)
		outFile << "-"; 
	outFile << endl;
}


//*********************************************************************************

void Name (ifstream& inFile, string& first, string& last, string& name)
//gets the name as individual strings and then cats them together into one string
{
	inFile >> first >> last;
	name = first + " " + last;
}

//*********************************************************************************

int OpenOutFile (ofstream& outFile, string& first, string& last, string& name)
//open output file using name of client as one word
{
	//local variable
	string outFileName;
		
	outFileName = first+last+".dat";
	outFile.open (outFileName.c_str());
	if (!outFile)
	{
		cout << "Unable to open output file.\n";
		return 1;
	}
}

//*********************************************************************************

void GetInfo (ifstream& inFile, int& adults, int& kids, char& type, char& hall, 
			string& day, float& deposit)
//get the rest of the data from input file
{
	inFile >> adults;
	inFile >> kids;
	inFile >> type;
	inFile >> hall;
	inFile >> day;
	inFile >> deposit;
	string skip;
	getline(inFile, skip);
}

//*********************************************************************************

void FoodCost (int& adults, int& kids, char& type, float& mTotal, float& tax, 
				float& aMeal, float& kMeal, string& mealType)
//calculates all costs related to food
{	
	//set meal prices
	if (type == 's' || type == 'S')
	{
		mealType = "Standard";
		aMeal = 11.75;
		kMeal = 11.75 * 0.6;
	}
	else if (type == 'd' || type == 'D')
	{
		mealType = "Deluxe";
		aMeal = 15.80;
		kMeal = 15.80 * 0.6;
	}
	
	//calculate food total
	mTotal = (aMeal * adults) + (kMeal * kids);
	
	//calculate tax and tip on food
	tax = mTotal * 0.18;
}

//*********************************************************************************

void HallCost (char& hall, string& day, float& surcharge, float& room)
//calculates all costs related to the banquet hall
{
	//set banquet hall price
	switch (hall)
	{
		case 'A' : room = 55.00; break;
		case 'B' : room = 75.00; break;
		case 'C' : room = 85.00; break;
		case 'D' : room = 100.00; break;
		case 'E' : room = 130.00; break;
	}
	
	//set surcharge amount
	if (day == "Friday" || day == "Saturday" || day == "Sunday")
		surcharge = (room + mTotal) * 0.07;
	else 
		surcharge = 0.0;
}

//*********************************************************************************

void Total (float& mTotal, float& tax, float& room, float& surcharge, float& deposit, 
			float& total, float& grTotal, float& rate, float& rDiscount)
//calculates the various totals
{
	
	//calculate total before deposit
	total = mTotal + tax + room + surcharge;
	
	//calculate grand total
	grTotal = total - deposit;

	//set discount rate based on grand total
	if (total < 100.00)
		rate = .005;
	else if (total >= 100.00 && total < 200.00)
		rate = .015;
	else if (total >= 200.00 && total < 400.00)
		rate = .03;
	else if (total >= 400.00 && total < 800.00)
		rate = .04;
	else if (total >= 800.00)
		rate = .05;
	
	//calculate discount
	discount = total - (total * rate) - deposit;
	
	//round the floating point down
	rDiscount = floorf (discount * 100) / 100;
}

//*********************************************************************************

void PrintBill (ofstream& outFile)
{
	outFile << fixed << setprecision(2);
	
	Dashes (outFile);
	
	outFile << "CUSTOMER 1: " << setw(37) << name << endl;
	outFile << "Number of Adults served:" << setw(25) << adults << endl;
	outFile << "Number of Children served:" << setw(23) << kids << endl;

	//formats output based on number of characters in variable: mealType
	if (mealType == "Standard")
		outFile << "Meal Type:" << setw(39) << mealType << endl;
	else if (mealType == "Deluxe")
		outFile << "Meal Type:" << setw(39) << mealType << endl;
	
	outFile << "Cost of an Adult meal:" << setw(22) << "$" << aMeal << endl;
	outFile << "Cost of a Child meal:" << setw(24) << "$" << kMeal << endl;
	
	//formats output based on number of characters in variable: mTotal
	if (mTotal >= 1000)
		outFile << "Total Food Cost:" << setw(26) << "$" << mTotal << endl;
	else if (mTotal < 1000)
		outFile << "Total Food Cost:" << setw(27) << "$" << mTotal << endl;
	
	//formats output based on number of characters in variable: tax
	if (tax >= 100)
		outFile << "Tip and Tax:" << setw(31) << "$" << tax << endl;
	else if (tax < 100)
		outFile << "Tip and Tax:" << setw(32) << "$" << tax << endl;
	
	//formats output based on number of characters in variable: room
	if (room >= 100)
		outFile << "Room Cost:" << setw(33) << "$" << room << endl;
	else if (room < 100)
		outFile << "Room Cost:" << setw(34) << "$" << room << endl;
	
	//formats output based on number of characters in variable: surcharge
	if (surcharge >= 100)
		outFile << "Surcharge for weekend:" << setw(21) << "$" << surcharge << endl;
	else if (surcharge > 0 && surcharge < 100)
		outFile << "Surcharge for weekend:" << setw(22) << "$" << surcharge << endl;
	else if (surcharge == 0)
		outFile << "Surcharge for weekend:" << setw(23) << "$" << surcharge << endl;

	Dashes (outFile);
	
	//formats output based on number of characters in variable: total
	if (total >= 1000)
		outFile << "TOTAL BILL:" << setw(31) << "$" << total << endl;
	else if (total < 1000)
		outFile << "TOTAL BILL:" << setw(32) << "$" << total << endl;
	
	//formats output based on number of characters in variable: discount
	if (deposit >= 100)
		outFile << "Deposit paid:" << setw(30) << "$" << deposit << endl;
	else if (deposit < 100)
		outFile << "Deposit paid:" << setw(31) << "$" << deposit << endl;
	
	Dashes (outFile);
	
	//formats output based on number of characters in variable: grTotal
	if (grTotal >= 1000)
		outFile << "YOU OWE:" << setw(34) << "$" << grTotal << endl;
	else if (grTotal < 1000)
		outFile << "YOU OWE:" << setw(35) << "$" << grTotal << endl;
	
	outFile << "If you pay within 10 days\n";
	
	//formats output based on number of characters in variable: discount
	if (discount >= 1000)
		outFile << "Your discounted total is:" << setw(17) << "$" << rDiscount << endl;
	else if (discount < 1000)
		outFile << "Your discounted total is:" << setw(18) << "$" << rDiscount << endl;

	Dashes (outFile);
	Dashes (outFile);
	
}