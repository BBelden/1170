//Author: Benjamin Belden
//Section: 001
//FILE: ola1.cc
//Purpose: This program will determine the average
//			of three test scores.

#include <iostream>

using namespace std; 

int main ()
{
	
			//Variable declarations...
			int test1;
			int test2, test3;  //notice more than one variable can be declared on same line if same data type
			float average;
	
			//Read in the three test scores
			cout << "Enter the first test score: ";
			cin >> test1;
			cout << "Enter the second test score: ";
			cin >> test2;
			cout << "Enter the third test score: ";
			cin >> test3;
	
			//calculate the average of the test scores
			average = (test1 + test2 + test3)/3;
	
			//Display the results
			cout << "The average of the three scores is: ";
			cout << average;
			cout << endl;
			
			return 0;
			
}