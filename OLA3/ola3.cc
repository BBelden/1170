//Name:       Ben Belden
//Section:    CSCI 1170-001
//Assignment: Open Lab Assignment #3
//Due:        23:59, September 28, 2012
//Purpose:    To gather the first and last name of a user, display their 
//            first and last name together in the console, and then to 
//            display their name in Pig Latin.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main ()
{
	
	//declare variables 
		
	string first, firstLow, firstUp, firstPigLow, firstPigUp;
	char fCh1, fCh2, fCh3;
	string last, lastLow, lastUp, lastPigLow, lastPigUp;
	char lCh1, lCh2, lCh3;
	

	//assign input from the user to be stored into variables
	
	cout << "\nType in your first name and then hit Enter.\n";
	cin >> first;
	cout << "Type in your last name and then hit Enter.\n";
	cin >> last;

	
	fCh1 = tolower(first.at(0));										//changes first letter of first name to lowercase
	firstLow = fCh1 + first.substr(1, first.length());					//concatenates first name with lowercase first letter
	fCh2 = toupper(first.at(0));										//changes first letter of first name to uppercase
	firstUp = fCh2 + first.substr(1, first.length());					//concatenates first name with uppercase first letter
	firstPigLow = first.substr(1, first.length()) + fCh1 + "ay";		//changes first name into pig latin
	fCh3 = toupper(firstPigLow.at(0));									//changes first letter of pig latin first name into uppercase
	firstPigUp = fCh3 + firstPigLow.substr(1, firstPigLow.length());	//concatenates first pig latin name with uppercase first letter
	
	lCh1 = tolower(last.at(0));											//changes first letter of last name to lowercase
	lastLow = lCh1 + last.substr(1, last.length());						//concatenates last name with lowercase first letter
	lCh2 = toupper(last.at(0));											//changes first letter of last name to uppercase
	lastUp = lCh2 + last.substr(1, last.length());						//concatenates last name with uppercase first letter
	lastPigLow = last.substr(1, last.length()) + lCh1 + "ay";			//changes last name into pig latin
	lCh3 = toupper(lastPigLow.at(0));									//changes first letter of pig latin last name into uppercase
	lastPigUp = lCh3 + lastPigLow.substr(1, lastPigLow.length());		//concatenates last pig latin name with uppercase first letter
		
		
	//display the first and last name together with a space between them
	
	cout << "\nYour full name is: " + firstUp + " " + lastUp << endl;
	
	//display the first and last name in Pig Latin with a space between them

	cout << "\nAnd your name in Pig Latin is: " + firstPigUp + " " + lastPigUp << endl;

	return 0;
	
}