#include <iostream>

using namespace std;

int main()
{
	
	float weight, height, floatBMI;
	int intBMI;
	
	cout <<"Please enter weight in kilograms: ";
	cin >> weight;
	cout <<"Please enter height in meters: ";
	cin >> height;
	floatBMI = weight /(height * height);  //rounds up
	intBMI = (int) ((floatBMI * 100)+0.5);
	cout << "BMI is: " << (float) intBMI/100 << "\n";
	
	
	
	return 0;
	}
	
