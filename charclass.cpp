//charclass.cpp
//classify a user entered character as
//upper case,  lower case,  digit(number), non alpha numeric
#include <iostream>

using namespace std;

int main(){
	char userInput;
	cout << "Enter an character: ";
    cin >> userInput;
    //don't need to use ascii character value.  Can use single quote
    if( userInput >='a' && userInput <='z')
    	cout << userInput << " is lower case\n";
    else if (userInput >='A' && userInput <='Z')
    	cout << userInput << " is UPPER case\n";
    else if (userInput >='0' && userInput <='9')
        cout << userInput << " is a digit \n";
    else
    	cout << userInput << " is non-alpha-numeric\n";
    	
    	
    	
    cout << "\n";
        
	return 0;
}
