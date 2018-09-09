//Name:       Ben Belden
//Section:    CSCI 1170-001
//Assignment: Open Lab Assignment #4
//Due:        23:59, October 12, 2012
//Purpose:    To read data from a file, find the first three commas in  
//            the file, and then output the first word following each of  
//            the first three commas in the file.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main ()
{
	//declare variables
	string word1, word2, word3, testFile;
	ifstream myFile; 
	
	//display purpose to user
	cout << "\nWelcome to OLA4. This program will ask you for a filename.\n";
	cout << "Then the program will tell you what 3 words come after the\n";
	cout << "first 3 commas in your file.\n\n";
	
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
	
	//extract first word following first three commas
	myFile.ignore (250, ',');		//ignore all up to a comma
	myFile >> word1;				//capture next word and assign it to a variable
	
	myFile.ignore (250, ',');		//do it again
	myFile >> word2;
	
	myFile.ignore (250, ',');		//do it again
	myFile >> word3;
	
	//display results to user
	cout << "\nThe first 3 words following the first 3 commas in your file are: \n";
	cout << word1 << endl;
	cout << word2 << endl;
	cout << word3 << endl;
	cout << "Thanks for participating.\n";
	
	//close file
	myFile.close();					
	
	return 0;
}
