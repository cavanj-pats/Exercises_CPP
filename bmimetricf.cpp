//does not work with printf.  must be missing an include....
//#include <iostream>
//#include <stdio.h>

//using namespace std;



float bmimetricf(int weight, float height){
	float floatBMI = 0;
	floatBMI = (float) weight /(height * height);  //rounds up
	return floatBMI;
}


/*
int main()
{
	
	float  height=1.58;
	int weight=50;
	/*
	cout <<"Please enter weight in kilograms: ";
	cin >> weight;
	cout <<"Please enter height in meters: ";
	cin >> height;
	floatBMI = weight /(height * height);  //rounds up
	intBMI = (int) ((floatBMI * 100)+0.5);

	*/

	//cout << "BMI is: " << bmimetricf(weight, height) << "\n";
	//printf(“BMI is: %3.2f”, bmimetricf(weight, height)) ;
	
	
	//return 0;
	//}
	
