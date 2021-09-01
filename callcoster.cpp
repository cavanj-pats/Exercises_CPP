#include <iostream>
#include <string>
#include <math.h>


using namespace std;

float costPerMinute(string day, int startTime){
    bool weekDay;
    if (day == "Mon") weekDay = true;
    if (day == "Tue") weekDay = true;
    if (day == "Wed") weekDay = true;
    if (day == "Thr") weekDay = true;
    if (day == "Fri") weekDay = true;
    if (day == "Sat" || day == "Sun") weekDay = false;

    if (weekDay && (startTime >= 800 && startTime <= 1800)) return 0.4;
    if (weekDay && ( startTime <800 || startTime >1800)) return 0.25;
    return 0.15;

}


int main()
{
	int timeStart, duration;
    string dday;
	
	
	cout <<"Enter the day the call started at: ";
	cin >> dday;
	cout <<"Enter the time the call started at (hhmm): ";
	cin >> timeStart;
	cout << "Enter the duration of the call (in minutes): ";
	cin >> duration;
	
    printf("This call will cost $%2.2f \n", costPerMinute(dday, timeStart)*duration);
    
	
	
	
	return 0;
	}
	
