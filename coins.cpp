#include <iostream>


using namespace std;

int main()
{
	int quarters, nickels, dimes, pennies, totalCents, totalDollars, centsBalance;
	//float totalDollars;
	
	cout <<"Please enter the amount of money to convert:"<< endl<<endl;
	cout << "# of dollars: " ;
	cin >> totalDollars;
	cout << "# of cents: ";
	cin >> totalCents;
	centsBalance = totalDollars * 100 + totalCents;
	quarters = centsBalance /25;	
	centsBalance -= quarters*25;
	dimes = centsBalance / 10;
	centsBalance -= dimes*10;
	nickels = centsBalance / 5;
	centsBalance -= nickels*5;
	pennies = centsBalance;
	cout << "The coins are " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies \n";
	
	
	return 0;
	}
	
