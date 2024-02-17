//increase size of array
//abdul IncreaseArraySize.cpp



#include <stdlib.h>
#include <stdio.h>
#include <cmath>
//#include <iostream>   
//#include <cstdio>
//#include <iomanip>



using namespace std;


int main()
{

    //c++
    int * p = new int[5];
    p[0]=3 ; 
    p[1]=8; 
    p[2]=9; 
    p[3]=2; 
    p[4]=1;
    for(int i=0; i<5; i++){
       printf("%d ", p[i]) ;
    }

   //cout << endl;
    printf("\n");

    int * q = new int[10];
    for(int i = 0; i<5; i++)
    {
        q[i] = p[i];
        q[i+5] = 0;
    }

    delete[] p;  //delete and free the old p
    p = q;  //assign p to the new, larger array 
    q = NULL;  //free the old pointer so to speak

    for (int i=0; i<10; i++)
     {   
        //cout<< p[i];
        printf("%d ",p[i]);
     }

    //cout << endl;
    printf("\n");

    
    
    return 0;


}
