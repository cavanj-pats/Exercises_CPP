//taylor sereis   


#include <stdio.h>

using namespace std;



long int fastpow(int m, int n){
    if (n==0)
        return 1;
    
    if (n%2 == 0)
        return fastpow(m*m, n/2);
    else  
        return m*fastpow(m*m, n/2);  //im assuning integer division of odd number will be correct
                                    // 5/2 = 2  same as (5-1)/2
}

long int factorialN(int n){
    if (n>1){
        return n*factorialN(n-1);
    
    }else{
        return 1;
    }
}

double  e_to_x(int x, int numTerms){
    //****   USES LOOP ****
    long int p = 0;
    long int f = 0;
    double val = 0.0;

    for (int i=0; i<=numTerms; i++){
        p = fastpow(x,i);
        f = factorialN(i);
        val += (double) p/ (double) f;
    }
    return val;
}

double taylorApproximation (int x, int numTerms){
    static double val = 0;
    static long int n;
    static long int d;
    
    if(numTerms == 0)
        return 1.0; 
    
    val = taylorApproximation(x, numTerms-1);
    n = fastpow(x,numTerms);  //if you assign the value here it is important for static variable
    d = factorialN(numTerms);
    return val + (double) n /(double) d;
}

//abdul's simple code.  Did not re-use power or factorial     O(n^2)
double e(int x, int n)
{
    //abdul's code
    static double p = 1.0, f = 1.0;
    double res = 0.0;

    if (n == 0)
        return 1;
    
    res = e(x, n-1);
    p = p * x;
    f = f * n;
    return res + p/f;

}

//ABDUL'S approach using Horner's rule   O(n)
double eh(int x, int n)
{
    // e^x = 1 + X/1 [ 1 + X/2 [1 + X/3]] ...
    double static s = 1 ;
    if (n == 0)
        return s;

    s = 1 + (double) x/ n * s;  //ok to type cast the numerator only as the integer division will result in double
    
    return eh(x,n-1);
}

//implementation using LOOP iteration
double ie(int x, int n)
{
    double s = 1;
    double num = 1.0;
    double den = 1.0;
    

    for (int i = 1; i<n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main(){
    int terms = 15;
    int power = 1;    
    double exp = e_to_x(power,terms);
    double r = taylorApproximation(power, terms);
    double res = e(power,terms);

    printf("e raised to %d:=%f\n",power,exp);
    printf("E raised to the %d power = %f\n", power, r);
    printf("abdul e raised to %d:=%f\n", power, res);
    printf("abdul Horner's  e raised to %d:=%f\n", power, eh(power,terms));
    printf("abdul Horner's iterative  e raised to %d:=%f\n", power, ie(power,terms));


    return 0;
}