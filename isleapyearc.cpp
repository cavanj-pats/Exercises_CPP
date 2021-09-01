//isleapyearc.cpp
//Leap Year Command Line Lab
#include <iostream>
#include <stdlib.h>  //for conversion of command line argument to int

using namespace std;

int main(int argc, char *argv[]){
	int year;
	bool isleap = false;
	year = (int) strtol(argv[1], NULL, 10);
	
	

	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				isleap = true;
			else
				isleap = false;
		}
		else {
			isleap = true;
		}
	}
	else {
		isleap = false;
	}
		
	

	if (isleap)
		cout << year << " was a leap year";
	else
		cout << year << " was not a leap year";
   
        
        
    
        
	return 0;
}
