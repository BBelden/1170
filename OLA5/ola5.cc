//Name:       Ben Belden
//Section:    CSCI 1170-001
//Assignment: Open Lab Assignment #5
//Due:        23:59, October 26, 2012
//Purpose:    To read data from a file, find each comma in  
//            the file, and then output each word following each of  
//            the commas in the file.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main ()
{

	//declare variables
	string word, testFile;
	int counter = 1;
	ifstream myFile; 
	
	//display purpose to user
	cout << "\nWelcome to OLA5. This program will ask you for a filename.\n";
	cout << "Then the program will tell you what words come after each\n";
	cout << "comma in your file.\n\n";
	
	//ask user to give name of input file
	cout << "Enter the input file name: ";
	cin >> testFile;
	
	//open file
	myFile.open(testFile.c_str());
	
	//if can't open file, display to user
	if (!myFile)
	{
		cout << "Check your file name. I cannot open that input file.\n";
		return 1;
	}
	cout << "The words following each comma in this file are:\n";
	
	//prime the loop
	myFile.ignore (500, ',');		//ignore all up to a comma
	myFile >> word;					//capture next word and assign it to a variable

	//extract first word following first three commas
	while (myFile)
	{
		if (word.at (word.length() -1) == ',')
			word = word.substr (0, word.length() -1);
		cout << counter << ". " << word << endl;
		counter++;
		myFile.ignore (500, ',');		//ignore all up to a comma
		myFile >> word;					//capture next word and assign it to a variable
	}
	
	return 0;
	
}

