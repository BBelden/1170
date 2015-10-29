//Name:       Ben Belden
//Section:    CSCI 1170-001
//Assignment: Final Exam
//Purpose:    The purpose of this program will be to get input from a user and  
//			  check a file for a match, then print the info back to the user 
          

#include <iostream>		//for cin/cout
#include <fstream>		//for input/output files


using namespace std;

//global variable declarations
string fName, lName;
ifstream inFile;

struct StudentInfo
{
	string firstName;
	string lastName;
	string year;
	float gpa;
	string phone;
};
StudentInfo student;


//function prototypes
int GetStudent (string& fName, string&lName);
void OpenFile (ifstream& inFile);
void GetInfo (ifstream& inFile, StudentInfo& student);
void StudentSearch (ifstream& inFile, StudentInfo& student);
int GetAnotherStudent (string& fName, string& lName);


//main function
int main ()
{	
	GetStudent (fName, lName);
	
}


//*******************

int GetStudent (string& fName, string& lName)
{
	cout << "Enter a first and last name of the student you need to look up." << endl;
	cout << "Or enter 'Q Q' to Quit." << endl;
	cin >> fName >> lName;
	if (fName == "Q")
	{
		cout << "Goodbye!\n";
		return 1;
	}
	else 
		cout << "You have entered: " << fName << " " << lName << endl;
		OpenFile (inFile);
		StudentSearch (inFile, student);
	return 2;
}

//*******************

void OpenFile (ifstream& inFile)
{
	inFile.open ("StudentInfo.txt");
	string print;
	//getline (inFile, print);
	//cout << print;
}	
	
//********************************

void GetInfo (ifstream& inFile, StudentInfo& student)
{
	inFile >> student.firstName;
	inFile >> student.lastName;
	inFile >> student.year;
	inFile >> student.gpa;
	inFile >> student.phone;
	string skip;
	getline(inFile, skip);

}

//********************************

void StudentSearch (ifstream& inFile, StudentInfo& student)
{
	bool search = false;
	char fCh1, lCh1;
	GetInfo (inFile, student);
		
	while (inFile && search == false)
	{
		if (student.firstName != fName || student.lastName != lName)
		{
			GetInfo (inFile, student);
		}
		
		if (student.firstName == fName && student.lastName == lName)
		{
			search = true;
			cout << "\nMatch found!!\n\n";
			cout << "Here is the information requested: \n";
			cout << student.firstName << " " << student.lastName << endl;
			cout << student.year << endl;
			cout << student.gpa << endl;
			cout << student.phone << endl;
			fCh1 = tolower(student.firstName.at(0));
			lCh1 = tolower(student.lastName.at(0));
			cout << fCh1 << lCh1 << student.lastName.substr(1, student.lastName.length()) ;
			cout << "@mtmail.mtsu.edu\n";
			
			if (student.year == "Freshman")
				cout << "Student is expected to graduate in three years.\n\n"; 
			else if (student.year == "Sophomore")
				cout << "Student is expected to graduate in two years.\n\n"; 
			else if (student.year == "Junior")
				cout << "Student is expected to graduate in one year.\n\n"; 
			else if (student.year == "Senior")
				cout << "Student is expected to graduate this year.\n\n"; 
			
			inFile.close ();
			GetAnotherStudent (fName, lName);
		}
	}
		
	if (search == false)
	{
		cout << "\nNo match found.\n\n";
		inFile.close ();
		GetAnotherStudent (fName, lName);
	}
}
	
//********************************

int GetAnotherStudent (string& fName, string& lName)
{
	cout << "Enter another first and last name of the student you need to look up." << endl;
	cout << "Or enter 'Q Q' to Quit." << endl;
	cin >> fName >> lName;
	if (fName == "Q")
	{
		cout << "Goodbye!\n";
		return 1;
	}
	else 
		cout << "You have entered: " << fName << " " << lName << endl;
		OpenFile (inFile);
		StudentSearch (inFile, student);
	return 2;

}