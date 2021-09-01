#include <iostream>
#include <cmath>

using namespace std;
//
const int NO_SOLUTION=0;
const int ONE_REAL_SOLUTION=1;
const int TWO_REAL_SOLUTIONS=2;
const int ALL_REALS=3;
const int NO_REAL_SOLUTION=4;

/*
quadratic solves ax^2+bx+c=0 equations
Input are the coefficients
output the solutions if they exist and type of solutions
Assumptions:  a is not zero,  is a quadratic equation.
    if one solution it will be x1 and assume it is the same as x2
    if no real solution the values of the output are not defined.
*/
int quadratic( double a, double b, double c, double& outX1, double& outX2);



int main()
{
	double a, b, c, x1, x2;

    
	
	cout <<"Please enter your coefficients a b c: ";
    cin >> a >> b >> c;
	
	cout << "The solutions to " << a <<"X^2 + " << b <<"X + " << c << " = 0   is \n";
	
    switch (quadratic(a, b, c, x1, x2)){
     case NO_SOLUTION:
        cout << "There is no solution. \n"; break;
     case ONE_REAL_SOLUTION:
        cout << "The Solution is "<< x1 << "\n"; break;
     case TWO_REAL_SOLUTIONS:
        cout << "The Solutions are "<< x1 << " " << x2 << "\n"; break;
     case ALL_REALS:
        cout <<"All Real Numbers represent a solution! \n"; break;
     case NO_REAL_SOLUTION:
        cout << "There is no real solution! \n"; break;
     default:
     cout << "Error in your equation.\n"; break;


    }
	return 0;
	}
	
int quadratic( double a, double b, double c, double& outX1, double& outX2){
    int res = -1;  //use -1 to perhaps throw an error
    double discriminant = (b*b - 4*a*c);
    
    if (a==0) {
        res = 3; 
    }
    else if (discriminant<0) {
        res = 4; //complex solution
    }
    else if (discriminant>0){
        //two real solutions
        outX1 = (-1*b + sqrt(b*b-4*a*c))/(2*a);
        outX2 = (-1*b - sqrt(b*b-4*a*c))/(2*a);
        res=2;
    }
    else if (discriminant==0){
         res =1;
         outX1 = (-1*b + sqrt(b*b-4*a*c))/(2*a); //they are the same....
    }
    else
            res=0;
    
     return res;

}