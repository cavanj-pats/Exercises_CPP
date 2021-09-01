//leapyearf.cpp
//leap year function tester

#include <iostream>
//#include "isleapyearf.h"

using namespace std;


bool isleapyear(int inyear){
	if (inyear % 4 == 0) {
		if (inyear % 100 == 0) {
			if (inyear % 400 == 0)
				return true;
			else
				return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}




int main(){
    int mybirthyear = 2000;
    
    if(isleapyear(mybirthyear))
    cout << "Your birthyear " << mybirthyear << " is a leap year\n ";

    return 0;
}