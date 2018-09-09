//Name:       Ben Belden
//Section:    CSCI 1170-001
//Assignment: Open Lab Assignment #2
//Due:        23:59, September 14, 2012
//Purpose:    To calculate how many miles you can drive in
//            two different vehicles on a full tank of gas.
 
 
 #include <iostream>
 #include <iomanip>
 #include <string>
 
 using namespace std;
 
 int main ( )
 
 {
 
		//declare variables section
 
		string car1Make, car1Model, car1Year;
		float car1Mpg1, car1Mpg2;
		float car1Miles1, car1Miles2;
		float comb1;
 
		string car2Make, car2Model, car2Year;
		float car2Mpg1, car2Mpg2;
		float car2Miles1, car2Miles2;
		float comb2;
 
		//declare the constant section
 
		const string STARS = "***********************************************************************************";
 
		//display purpose of the program to end user
 
		cout << endl << STARS << endl << STARS << endl;
		cout << "This program will give you a chart of how many miles you can travel in the city,\n";
		cout << "or on the highway, and the combined average for two different vehicles, assuming\n";
		cout << "you had a full tank of gasoline of 20 gallons.\n";
		cout << "You will enter some data for two different vehicles and then the chart will be\n";
		cout << "displayed. Be sure to press ENTER after typing the answer to each question.\n";
		cout << STARS << endl << STARS << endl << endl;
 
		//assign input from the user to be stored into each variable for the first vehicle
 
		cout << "What is the make of your first auto (For example; Honda)?\n";
		cin >> car1Make;
		cout << "What is the model name of your first auto (For example; Accord)?\n";
		cin >> car1Model;
		cout << "What is the year of your first auto (For example; 2010)?\n";
		cin >> car1Year;
		cout << "How many miles per gallon does it get in the city?\n";
		cin >> car1Mpg1;
		cout << "How many miles per gallon does it get on the highway?\n";
		cin >> car1Mpg2;
 
		//assign input from the user to be stored into each variable for the second vehicle
 
		cout << endl << "Now what is the make of your second auto (For example; Honda)?\n";
		cin >> car2Make;
		cout << "What is the model name of your second auto (For example; Accord)?\n";
		cin >> car2Model;
		cout << "What is the year of your second auto (For example; 2010)?\n";
		cin >> car2Year;
		cout << "How many miles per gallon does it get in the city?\n";
		cin >> car2Mpg1;
		cout << "How many miles per gallon does it get on the highway?\n";
		cin >> car2Mpg2;
 
		//convert MPG into total miles on a tank
 
		car1Miles1 = car1Mpg1 * 20;
		car1Miles2 = car1Mpg2 * 20;
		car2Miles1 = car2Mpg1 * 20;
		car2Miles2 = car2Mpg2 * 20;
 
		//average city and highway miles
 
		comb1 = (car1Miles1 + car1Miles2) / 2;
		comb2 = (car2Miles1 + car2Miles2) / 2;
 
		//display of data in columns
 
		cout << endl << STARS << endl << STARS << endl;
		cout << "**Here is how many miles you can expect to travel on a tank of 20 gallons of gas!**\n";
		cout << STARS << endl;
		cout << "YEAR" << setw(15) << "MAKE" << setw(15) << "MODEL" << setw(15)<<"CITY" << setw(15) << "HIGHWAY" << setw(15) << "COMBINED" << endl;
		cout << "----" << setw(15) << "----" << setw(15) << "-----" << setw(15) << "----" << setw(15) << "-------" << setw(15) << "--------" << endl;
		cout << car1Year << setw(15) << car1Make << setw(15) << car1Model << setw(15) << car1Miles1 << setw(15) << car1Miles2 << setw(15) << comb1 << endl;
		cout << car2Year << setw(15) << car2Make << setw(15) << car2Model << setw(15) << car2Miles1 << setw(15) << car2Miles2 << setw(15) << comb2 << endl;
		cout << STARS << endl << STARS << endl;
 
		return 0;
 
 }