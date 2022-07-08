//udemy practice



#include <iostream>
#include <stdio.h>

using namespace std;



int main(){
    int a[5];
    int b[5] = {1,3,5,7,9};


    for (int i = 0; i<5; ++i){
       if (i == 4)
        printf("%d\n",b[i]);
       else
       printf("%d, ",b[i]) ;

       
    } 




    return 0;
}