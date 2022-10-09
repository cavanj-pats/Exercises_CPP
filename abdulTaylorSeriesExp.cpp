//taylor sereis   


#include <stdio.h>

using namespace std;



int fastpow(int m, int n){
    if (n==0)
        return 1;
    
    if (n%2 == 0)
        return fastpow(m*m, n/2);
    else  
        return m*fastpow(m*m, n/2);  //im assuning integer division of odd number will be correct
                                    // 5/2 = 2  same as (5-1)/2
}

int factorialN(int n){
    if (n>1){
        return n*factorialN(n-1);
    
    }else{
        return 1;
    }
}

double e_to_x(int x, int numTerms){
    //****   USES LOOP ****
    int p = 0;
    int f = 0;
    static double val = 0.0;

    for (int i=0; i<=numTerms; i++){
        p = fastpow(x,i);
        f = factorialN(i);
        val += (double) p/ (double) f;
    }
    return val;
}

double taylorApproximation (int x, int numTerms){
    //static double val = 0;
    //val = fastpow(x,numTerms) / factorialN(numTerms);
    //static int currTerm;

    if(numTerms == 0)
        return 1.0; 
    

    long int n = fastpow(x,numTerms);
    long int d = factorialN(numTerms);
    
    return  fastpow(x,numTerms) / factorialN(numTerms) + taylorApproximation(x,numTerms-1);

}


int main(){
    int terms = 8;
    int power = 3;
    double exp = e_to_x(power,terms);

    printf("e raised to %d:=%f\n",power,exp);

    return 0;
}