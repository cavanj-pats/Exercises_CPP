

#include <iostream>

using namespace std;

int main()
{	
	float weight, height, floatBMI;
	float pounds, inches;
	int intBMI;
	
	cout <<"Please enter weight in pounds: ";
	cin >> pounds;
	weight = pounds * 0.453592; //convert to KG leave rest of calculation alone
	cout <<"Please enter height in inches: ";
	cin >> inches;
	height = inches * 0.0254 ;   //convert to meters for calcs
	floatBMI = weight /(height * height);  //rounds up
	intBMI = (int) ((floatBMI * 100)+0.5);
	floatBMI = (float) intBMI/100;
	
	cout << "BMI is: ";
	printf ("%.2f", floatBMI);
	cout << "\n";
	
	
	return 0;
	}
	
