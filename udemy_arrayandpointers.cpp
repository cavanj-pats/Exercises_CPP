//udemy practice

//pointers allow access to heap memory.
//pointers can access data in a file.  pointer to a file.
//really anything external to a program.
/* pointers allow access to heap, "resources", and passing parameters */


#include <iostream>
#include <stdio.h>

using namespace std;



int main(){
    int a[5];
    int b[5] = {1,3,5,7,9};
    
    //pointers
    int aa = 10;
    int *p;
    p=&aa;



    for (int i = 0; i<5; ++i){
       if (i == 4)
        printf("%d\n",b[i]);
       else
       printf("%d, ",b[i]) ;

       
    } 




    return 0;
}