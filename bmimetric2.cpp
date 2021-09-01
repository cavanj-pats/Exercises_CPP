#include <iostream>
#include <string>
#include <math.h>


using namespace std;

string strCDC(float BMI){
    if (BMI >=30.0) return "Obese";
    if (BMI >=25.5) return "Overweight";
    if (BMI >=18.5) return "Normal";
    return "Underweight";
}

int main()
{
	
	float price1, price2, tax;
	char club;
	
	cout <<"Enter price of the first item: ";
	cin >> price1;
	cout <<"Enter price of the second item ";
	cin >> price2;
	cout << "Does customer have a club card? (Y/N): ";
	cin >> club;
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> tax;

	
	floatBMI = weight /(height * height);  //rounds up
	intBMI = (int) ((floatBMI * 100)+0.5);
	cout << "BMI is: " << (float) intBMI/100 << ", Status is "<< strCDC(floatBMI) << endl;
	
	
	
	return 0;
	}
	
