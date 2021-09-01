//evenodd.cpp
//calculate absolute value
#include <iostream>

using namespace std;

int main(){
	int num1, num2, num3, num4;
	int counteven=0;
	
	cout << "Please enter 4 positive integers, separated by a space:";
    cin >> num1 >> num2 >> num3 >> num4;

	if (num1 % 2 == 0)
		counteven++;
	if (num2 % 2 == 0)
		counteven++;
	if (num3 % 2 == 0)
		counteven++;
	if (num4 % 2 == 0)
		counteven++;

	switch (counteven) {
		case 4:
			cout << "more evens";
			break;
		case 3:
			cout << "more evens";
			break;
		case 2:
			cout << "same number of evens and odds";
			break;
		default:
			cout << "more odds";
	}
   
        
        
    
        
	return 0;
}
