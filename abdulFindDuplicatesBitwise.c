//abdulFindDuplicatesBitwise.c


#include "stdio.h"



int main()
{
    char A[]="finding";
    long int H=0, x = 0;

    for (int i=0; A[i]!='\0'; i++)
    {
        x=1; //set to 1 and then bit shift to position of letter
        x= x<<(A[i]-97);  //this now has the letter position flagged with "on"
        
        if((x & H) > 0)
            printf("%c is duplicated.\n", A[i]);
        else
            H=(x|H);

    }

    return 0;
}