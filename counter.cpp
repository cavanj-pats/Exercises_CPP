#include <iostream>


using namespace std;

int main()
{
	int quarters, nickels, dimes, pennies, totalCents, totalDollars;
	//float totalDollars;
	
	cout <<"Please enter the number of coins: "<< endl;
	cout << "# of quarters: " ;
	cin >> quarters;
	cout << "# of dimes: ";
	cin >> dimes;
	cout << "# of nickels: ";
	cin >> nickels;
	cout << "# of pennies: ";
	cin >> pennies;
	
	totalCents = quarters*25 + dimes*10 + nickels*5 + pennies;
	totalDollars = totalCents/100;
	
	
	
	cout << "The total is "<< totalDollars << " dollars and " << totalCents % 100 << " cents\n";
	
	return 0;
	}
	
