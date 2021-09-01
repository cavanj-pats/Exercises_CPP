#include <iostream>
//for math library some people in discussion are saying
//the define, and two includes
/* #define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
*/

//#include <string>

//this program runs and produces the result 30
//but the quiz answer is that it produces 'garbage'.

using namespace std;

int main()
{
	//quiz answer involving variable initialization
	int x;
	x=x+30;
	cout << x << endl;
	
	float y;
	y=3.0/4.0+3+2/5;
	cout << "float y = " << y << endl;
	
	
	return 0;
	}
	
