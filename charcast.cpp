//program to read a character and convert it to ascii using implicit cast
#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

int main()
{
	char inputChar;
	int asciiValue;
	
	cout << "Enter a character: " ;
	cin >> inputChar;
	asciiValue =inputChar;  //implicit casting
	
	cout << "\nCharacter " << inputChar << " in ascii is " << asciiValue;
	cout << "\n\n";
	/*
	char lowerCase, upperCase;
	int offset;
	cout << "Enter lower case letter \n";
	cin >> lowerCase;
	offset = (int) (lowerCase -'a');   //determime the offest to lower a
	upperCase = (char) ('A' + offset);
	//should now have upper case letter stored
	
	cout << "Upper Case conversion results in letter: " << upperCase <<endl;
	
	
	*/
	keep_window_open();
	
	return 0;
	}
	
