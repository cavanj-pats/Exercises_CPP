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
    double val = 0;
    static long int n;
    static long int d;
    
    if(numTerms == 0)
        return 1.0; 
    
    val = taylorApproximation(x, numTerms-1);
    n = fastpow(x,numTerms);  //if you assign the value here it is important for static variable
    d = factorialN(numTerms);
    return val + (double) n /(double) d;
   
    
    

}


int main(){
    int terms = 10;
    int power = 5;    
    double exp = e_to_x(power,terms);
    double r = taylorApproximation(power, terms);

    printf("e raised to %d:=%f\n",power,exp);
    printf("E raised to the %d power = %f\n", power, r);

    return 0;
}