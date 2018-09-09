//Name:       Ben Belden
//Section:    CSCI 1170-001
//Assignment: Open Lab Assignment #6
//Due:        23:59, November 2, 2012
//Purpose:    This program will output a design based on a number   
//            that the user types in. If the user types in a number  
//            that is 5 through 15 (including 5 and 15) it will 
//            output the corresponding design. So, for example, if
//            the number types in is 5, the output will be (start
//            with five stars, decrease down to 1, then do 1 again,
//            and increase back to 5):

#include <iostream>
#include <string>

using namespace std;

//function prototypes
void DrawTriangle (int, char);
void DrawInvertedTriangle (int, char);

//variable declarations
int h;
char c = '*';
string exit;

//main function
int main ()
{
	//intro to user	
	cout << "\nWelcome to Ben's happy fun land! Type a number from 5 to 15\n"; 
	cout << "(including 5 and 15) and I will draw you a super-neato design.\n";
	cout << "You can do it over and over, and then when you are overwhelmed\n";
	cout << "by all of the awesomeness, you may type in -1 to quit.\n\n";
	
	cin >> h; 		//prime the loop with user input

	while (cin) 
	{

		if (h >= 5 && h <= 15) //test whether input is within 5 to 15 inclusive
		{
			cout << endl << h << " is a super-great choice!\n\n";
			DrawInvertedTriangle (h, c); 	//call function
			DrawTriangle (h, c); 			//call function
			//prompt the user to try again
			cout << "\nBAM!! Cool, eh? Try it again, or type -1 to quit.\n\n"; 
			cin >> h; 			//user re-input
			continue;
		}
		if (h < 5 && h != -1) 	//test for less than requested range, excluding the exit input
		{	
			//to make it less boring
			switch (h)
			{
				case 4 : cout << "\n4 is soooo close, but not quite. Try again. (5 to 15)\n\n"; break;
				case 3 : cout << "\nCan't you read? Come on! 3 is NOT between 5 and 15.\n\n"; break;
				case 2 : cout << "\n2? How could you have possibly fat-fingered this? (5 to 15)\n\n"; break;
				case 1 : cout << "\n...... between 5 and 15. That means NOT 1, right?\n\n"; break;
				default : cout << endl << h << "??? *sigh* really? REALLY? I know you can do this. Pick a number between 5 and 15.\n\n"; break;
			}
			cin >> h; 			//user re-input
			continue;
		}
		if (h > 15) 			//test if greater than requested range
		{
			//to make it less boring again
			switch (h)
			{
				case 16 : cout << "\nWow. You came REALLY close to following the directions, didn't you? Is 16 between 5 and 15? Try again.\n\n"; break;
				case 17 : cout << "\nCongratulations! You just broke the program with your 17! While you think of a number between 5 and 15, I'll try to put the program back together.\n\n"; break;
				case 18 : cout << "\n18? Um. No. Just no. (5 to 15)\n\n"; break; 
				case 19 : cout << "\nSo. Yeah. 19. What should you have chosen? (5 to 15)\n\n"; break;
				default : cout << "\nIt's official. You don't know that " << h << " is greater than 15. Try again.\n\n"; break;
			}
			cin >> h;			//user re-input
			continue;
		}
		if (h == -1)			//test for exit input
			break;				//break out of the loop
	}
	
	//switch (h)
		//case 
	
	cout << "\nAre you sure you want to exit?\n\n";
	cin >> exit;
	cout << "\n\nHA! You did anyway!\n\nIsn't your day SO much better? \nBye!\n\n";
	return 0;
	
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//function definitions

void DrawInvertedTriangle (int h, char c)
{
	int hCount = h;
	while (hCount >= 1)
	{
		int cCount = 1;
		while (cCount <= hCount)
		{
			cout << c;
			cCount++;
		}
		cout << endl;
		hCount--;
	}
}


void DrawTriangle (int h, char c)
{
	int hCount = 1;
	while (hCount <= h)
	{
		int cCount = 1;
		while (cCount <= hCount)
		{
			cout << c;
			cCount++;
		}
		cout << endl;
		hCount++;
	}
}

